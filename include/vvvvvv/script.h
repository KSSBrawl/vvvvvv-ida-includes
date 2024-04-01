//
// from vvvvvv/Script.h
//

#include "../cplusplus/types.h"
#include "textbox.h"

struct __declspec(align(4))
Script
{
  std::string name;
  std::vector contents;
};

#define NUM_SCRIPT_ARGS 40

enum StartMode
{
  Start_MAINGAME,
  Start_MAINGAME_TELESAVE,
  Start_MAINGAME_QUICKSAVE,
  Start_TIMETRIAL_SPACESTATION1,
  Start_TIMETRIAL_LABORATORY,
  Start_TIMETRIAL_TOWER,
  Start_TIMETRIAL_SPACESTATION2,
  Start_TIMETRIAL_WARPZONE,
  Start_TIMETRIAL_FINALLEVEL,
  Start_NODEATHMODE_WITHCUTSCENES,
  Start_NODEATHMODE_NOCUTSCENES,
  Start_SECRETLAB,
  Start_INTERMISSION1_VITELLARY,
  Start_INTERMISSION1_VERMILION,
  Start_INTERMISSION1_VERDIGRIS,
  Start_INTERMISSION1_VICTORIA,
  Start_INTERMISSION2_VITELLARY,
  Start_INTERMISSION2_VERMILION,
  Start_INTERMISSION2_VERDIGRIS,
  Start_INTERMISSION2_VICTORIA,
  Start_EDITOR,
  Start_EDITORPLAYTESTING,
  Start_CUSTOM,
  Start_CUSTOM_QUICKSAVE,
  Start_QUIT,
  Start_CUTSCENETEST,

  Start_FIRST_NODEATHMODE = Start_NODEATHMODE_WITHCUTSCENES,
  Start_LAST_NODEATHMODE = Start_NODEATHMODE_NOCUTSCENES,
  Start_FIRST_INTERMISSION1 = Start_INTERMISSION1_VITELLARY,
  Start_LAST_INTERMISSION1 = Start_INTERMISSION1_VICTORIA,
  Start_FIRST_INTERMISSION2 = Start_INTERMISSION2_VITELLARY,
  Start_LAST_INTERMISSION2 = Start_INTERMISSION2_VICTORIA,

  Start_FIRST_TIMETRIAL = Start_TIMETRIAL_SPACESTATION1
};

struct __declspec(align(4))
scriptclass
{
  std::vector commands;
  std::string words[NUM_SCRIPT_ARGS];
  std::vector txt;
  std::string scriptname;
  int position;
  int looppoint, loopcount;

  int scriptdelay;
  bool running;

  std::map textbox_colours;
  int textx;
  int texty;
  TextboxCrewmatePosition textcrewmateposition;
  TextboxOriginalContext textoriginalcontext;
  int r,g,b;
  bool textflipme;
  char textcase;
  bool textbuttons;
  bool textlarge;
  int textboxtimer;
  std::vector textbox_sprites;
  TextboxImage textbox_image;

  int i, j, k;

  std::vector customscripts;
};
