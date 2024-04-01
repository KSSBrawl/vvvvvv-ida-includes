//
// from vvvvvv/Map.h
//

#include "../cplusplus/types.h"
#include "finalclass.h"
#include "labclass.h"
#include "otherlevel.h"
#include "spacestation2.h"
#include "tower.h"
#include "warpclass.h"

struct __declspec(align(4))
Roomtext
{
  int x, y;
  const char* text;
  bool rtl;
};

enum RoomnameType
{
  RoomnameType_STATIC,
  RoomnameType_GLITCH,
  RoomnameType_TRANSFORM
};

struct __declspec(align(4))
Roomname
{
  int x;
  int y;
  bool loop;
  int flag;
  RoomnameType type;
  std::vector text;
  int progress;
  int delay;
};

struct __declspec(align(4))
mapclass
{
  bool nexttowercolour_set;

  int roomdeaths[20 * 20];
  int roomdeathsfinal[20 * 20];
  //int areamap[20 * 20]; <- REMOVED BY COMPILER
  int contents[40 * 30];
  bool explored[20 * 20];

  int background;
  int rcol;
  int tileset;
  bool warpx;
  bool warpy;

  const char* roomname;
  bool roomname_special;
  bool roomnameset;
  const char* hiddenname;

  std::vector specialroomnames;

  bool towermode;
  int ypos;
  int oldypos;
  int cameramode;
  int cameraseek, cameraseekframe;
  int resumedelay;
  bool minitowermode;

  int colstatedelay;
  int colsuperstate;
  int spikeleveltop, spikelevelbottom;
  int oldspikeleveltop, oldspikelevelbottom;
  bool finalmode;
  bool finalstretch;

  bool custommode;
  bool custommodeforreal;
  int custommmxoff, custommmyoff, custommmxsize, custommmysize;
  int customzoom;
  bool customshowmm;

  bool final_colormode;
  int final_mapcol;
  int final_aniframe;
  int final_aniframedelay;
  int final_colorframe, final_colorframedelay;

  std::vector teleporters;
  std::vector shinytrinkets;

  bool showteleporters, showtargets, showtrinkets;

  bool roomtexton;
  std::vector roomtext;

  otherlevelclass otherlevel;
  spacestation2class spacestation2;
  labclass lablevel;
  finalclass finallevel;
  warpclass warplevel;
  towerclass tower;
  int extrarow;

  bool invincibility;

  int cursorstate, cursordelay;
};
