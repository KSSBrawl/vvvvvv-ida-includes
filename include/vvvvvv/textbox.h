//
// from vvvvvv/Textbox.h
//

#ifndef TEXTBOX_H
#define TEXTBOX_H

//#include <stdint.h>
#include "../cplusplus/types.h"

struct __declspec(align(4))
TextboxCrewmatePosition
{
  bool override_x;
  bool override_y;
  int x;
  int y;
  int dir;
  bool text_above;
};

struct __declspec(align(4))
TextboxOriginalContext
{
  int x;
  int y;
  std::vector lines;
  std::string script_name;
  char text_case;
};

struct __declspec(align(4))
TextboxSpacing
{
  bool centertext;
  unsigned char pad_left;
  unsigned char pad_right;
  unsigned short padtowidth;
};

struct __declspec(align(4))
TextboxSprite
{
  int x;
  int y;
  int col;
  int tile;
};

enum TextboxImage
{
  TEXTIMAGE_NONE,
  TEXTIMAGE_LEVELCOMPLETE,
  TEXTIMAGE_GAMECOMPLETE
};

enum TextboxTranslate
{
  TEXTTRANSLATE_NONE,
  TEXTTRANSLATE_CUTSCENE,
  TEXTTRANSLATE_FUNCTION
};

struct textboxclass;
typedef void (*TextboxFunction)(textboxclass* THIS);

struct __declspec(align(4))
textboxclass
{
  std::vector lines;
  int xp, yp, w, h;
  int r, g, b;
  int linegap;
  int timer;

  float t1;
  float prev_t1;
  int tm;

  bool flipme;

  int rand;

  bool large;

  bool should_centerx;
  bool should_centery;

  unsigned int print_flags;
  TextboxTranslate translate;

  std::vector sprites;
  TextboxImage image;

  TextboxCrewmatePosition crewmate_position;
  TextboxOriginalContext original;
  TextboxSpacing spacing;
  TextboxFunction function;

  int other_textbox_index;
};

#endif // TEXTBOX_H
