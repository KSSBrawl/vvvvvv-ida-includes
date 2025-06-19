# vvvvvv-ida-includes

This is a collection of pseudo-C headers for use with IDA in order to ease updating VVVVVV's autosplitter.

## Maintaining

As of the last time this README has been updated, these headers support VVVVVV 2.4.3 specifically. If you are coming here and the current version of VVVVVV is not 2.4.3, you will need to update the class definitions in the `include/vvvvvv` folder to reflect changes made to them since then.

## How to use

After loading VVVVVV's executable into IDA, navigate to `File->Load file->Parse C header file...` in the menu and load `include/windows.h` if you are working on the Windows autosplitter file for LiveSplit, or `include/linux.h` if you are updating the Linux autosplitter for use with [pyautosplit](https://github.com/christofsteel/pyautosplit).

## Variables to search for

The Windows and Linux autosplitters use different names to identify internal VVVVVV variables, and in IDA you will be searching for the following:

### Windows

| LiveSplit.VVVVVV.asl          | Internal VVVVVV variable        |
|-------------------------------|---------------------------------|
| `gametimeFrames`              | `game.frames`                   |
| `gametimeSeconds`             | `game.seconds`                  |
| `gametimeMinutes`             | `game.minutes`                  |
| `gametimeHours`               | `game.hours`                    |
| `fadetomode`                  | `fadetomode` (Input.cpp)        |
| `gotomode`                    | `gotomode` (Input.cpp)          |
| `timetrialcountdown`          | `game.timetrialcountdown`       |
| `finalStretch`                | `map.finalstretch`              |
| `gamestate`                   | `game.state`                    |
| `firstTextLineSmall`          | `script.txt._Myfirst->_Bx._Buf` |
| `firstTextLineLarge`          | `script.txt._Myfirst->_Bx._Ptr` |
| `teleport_to_x`               | `game.teleport_to_x`            |
| `teleport_to_y`               | `game.teleport_to_y`            |
| `collect`                     | `obj.collect`                   |
| `menustate`                   | `game.gamestate`                |
| `ingame_titlemode`            | `game.ingame_titlemode`         |

### Linux

TODO

## But how do I find all of this shit?

If you know what you're doing, it's pretty simple. If you *don't* know what you're doing though, fear not because I have you covered.

### Windows

The Windows VVVVVV executable is compiled with very minimal debug symbols, but thankfully recent versions have added a command line option called `-addresses` that will list the memory addresses of all the game's main class instances. Most of the variables we care about are stored in these instances (we particuarly care about the `game`, `script`, `map`, and `obj` objects) but there are two that unfortunately are not stored in classes which makes things harder.

#### `game`, `script`, `map`, and `obj`

99% of what we care about is stored in these objects whose addresses the aforementioned `-addresses` command line option will give you right away. These are instances of the `Game`, `scriptclass`, `mapclass`, and `entityclass` classes respectively so go ahead and import the definitions from the files you loaded through the `Local types` view. After that, you can navigate to each instance by hitting the G key in the IDA View to pull up the `Jump to address` dialog, and type in the address of the instance you want. Once you have navigated to it, hit Alt+Q to pull up the `Choose a structure type` dialog and pick the correct one for the instance. With that, now you'll be able to expand the newly defined structure in IDA View and see the address of every one of its data members.

#### A note about `script`

What we specifically care about with this class is the `txt` variable, which is an `std::vector<std::string>` and more specifically we care about the `_Myfirst` variable contained within the `std::vector` class which is a pointer to the first element of the vector. The Visual Studio 2010 implementation of the `_String_val` class that `std::basic_string` (which `std::string` is an alias of) inherits from looks something like this:

```cpp
template <class _Elem, class _Alloc>
class _String_val : public _Container_base
{
public:
  enum { _BUF_SIZE = 16 / sizeof(_Elem) < 1 ? 1 : 16 / sizeof(_Elem) };

  union _Bxty
  {
    _Elem _Buf[_BUF_SIZE];
    _Elem *_Ptr;
    char _Alias[_BUF_SIZE];
  } _Bx;

  // there's more here but it's irrelevant to the topic
};
```

This `_Bx` union contains both an array to store short strings (`_Buf`) and a pointer for allocating space for strings that cannot fit in the array (`_Ptr`), which is why there are both `firstTextLineSmall` and `firstTextLineLarge` pointer variables in the autosplitter and why they have different levels of indirection.

#### `gotomode` and `fadetomode`

Unfortunately for us, these two variables are not neatly bundled up inside of classes but instead are global scope. You're gonna have to get your hands a bit dirty. Start by performing a text search for `13h` and pick the search result that looks something like `mov dword_[gibberish hex digits], 13h`. This will hopefully bring you to something that looks like this:

![A screenshot of the disassembler program IDA](media/gotomode_fadetomode.png)

If it did bring you to something like this, great! This is the `startmode()` function in `Input.cpp` and by cross-referencing with the source code we can glean the info we need:

```cpp
static void startmode(const enum StartMode mode)
{
    gotomode = mode;
    graphics.fademode = FADE_START_FADEOUT;
    fadetomode = true;
    fadetomodedelay = 19;
}
```

Because of how similar the assembly looks to the original source code we can safely assume that these operations are roughly 1-to-1. From this we can gleam that the first mystery address being modified is `gotomode` and the third is `fadetomode`, so go ahead and rename them to those names.

#### Fixing the addresses

The addresses listed in IDA do not actually match up with the addresses LiveSplit's autosplitter is going to need. To fix this, you'll need to subtract the program's base address from each address. In IDA, you can find this by scrolling up to the top of the disassembly, taking the first address in the listing, subtracting 0x1000 from it, and then subtracting the resulting number from every address you're putting into LiveSplit.
