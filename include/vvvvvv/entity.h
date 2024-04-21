//
// from vvvvvv/Entity.h
//

#include "../cplusplus/types.h"
#include "game.h"

enum
{
  BLOCK = 0,
  TRIGGER = 1,
  DAMAGE = 2,
  DIRECTIONAL = 3,
  SAFE = 4,
  ACTIVITY = 5
};

enum
{
  CYAN = 0,
  PURPLE = 20,
  YELLOW = 14,
  RED = 15,
  GREEN = 13,
  BLUE = 16,
  GRAY = 19,
  TELEPORTER = 102
};

struct __declspec(align(4))
entityclass
{
  std::vector entities;

  int k;


  std::vector blocks;
  bool flags[100];
  bool collect[100];
  bool customcollect[100];

  int platformtile;
  bool vertplatforms, horplatforms;

  bool nearelephant, upsetmode;
  int upset;

  int trophytext, trophytype;
  int oldtrophytext;

  int altstates;

  int customenemy;
  int customplatformtile;
  bool customwarpmode, customwarpmodevon, customwarpmodehon;
  std::string customscript;
  bool customcrewmoods[numcrew];
  std::string customactivitycolour;
  std::string customactivitytext;
  int customactivitypositiony;
};
