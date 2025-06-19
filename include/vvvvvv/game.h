#include "../sdl2/types.h"
#include "../cplusplus/types.h"
#include "enums.h"

//
// from vvvvvv/Game.h
//

enum MenuName
{
  mainmenu,
  playerworlds,
  confirmshowlevelspath,
  showlevelspath,
  levellist,
  quickloadlevel,
  deletequicklevel,
  youwannaquit,
  errornostart,
  errorsavingsettings,
  errorloadinglevel,
  warninglevellist,
  graphicoptions,
  ed_settings,
  ed_desc,
  ed_music,
  ed_quit,
  ed_font,
  options,
  gameplayoptions,
  speedrunneroptions,
  setglitchrunner,
  advancedoptions,
  audiooptions,
  accessibility,
  controller,
  language,
  translator_main,
  translator_options,
  translator_options_limitscheck,
  translator_options_stats,
  translator_options_exploregame,
  translator_options_cutscenetest,
  translator_maintenance,
  translator_maintenance_sync,
  translator_error_setlangwritedir,
  cleardatamenu,
  clearcustomdatamenu,
  setinvincibility,
  setslowdown,
  unlockmenu,
  credits,
  credits2,
  credits25,
  credits3,
  credits4,
  credits5,
  credits6,
  credits_localisations_implementation,
  credits_localisations_translations,
  play,
  unlocktimetrial,
  unlocktimetrials,
  unlocknodeathmode,
  unlockintermission,
  unlockflipmode,
  newgamewarning,
  playmodes,
  intermissionmenu,
  playint1,
  playint2,
  continuemenu,
  startnodeathmode,
  gameover,
  gameover2,
  unlockmenutrials,
  timetrials,
  nodeathmodecomplete,
  nodeathmodecomplete2,
  timetrialcomplete,
  timetrialcomplete2,
  timetrialcomplete3,
  gamecompletecontinue
};

#define numcrew 6

struct __declspec(align(4))
Summary
{
  bool exists;
  int seconds;
  int minutes;
  int hours;
  int saverx;
  int savery;
  int trinkets;
  bool crewstats[numcrew];
};

enum SLIDERMODE
{
  SLIDER_NONE,
  SLIDER_MUSICVOLUME,
  SLIDER_SOUNDVOLUME
};

enum SWNMODE
{
  SWN_GRAVITRON,
  SWN_SUPERGRAVITRON,
  SWN_START_GRAVITRON_STEP_3,
  SWN_START_GRAVITRON_STEP_2,
  SWN_START_GRAVITRON_STEP_1,
  SWN_FINISH_GRAVITRON_STEP_1,
  SWN_START_SUPERGRAVITRON_STEP_1,
  SWN_START_SUPERGRAVITRON_STEP_2,
  SWN_FINISH_GRAVITRON_STEP_2,
  SWN_NONE
};

struct __declspec(align(4))
Game
{
  char magic[16];

  struct Summary last_telesave, last_quicksave;
    
  const char* saveFilePath;

  int roomx, roomy;
  int prevroomx, prevroomy;

  int savex, savey, saverx, savery;
  int savegc, savedir;
  int savecolour;

  int edsavex, edsavey, edsaverx, edsavery;
  int edsavegc, edsavedir;

  int state, statedelay;

  bool glitchrunkludge;

  enum GameGamestate gamestate;
  enum GameGamestate prevgamestate;
  bool hascontrol, jumpheld;
  int jumppressed;
  int gravitycontrol;
  
  bool muted;
  int mutebutton;
  bool musicmuted;
  int musicmutebutton;

  int tapleft, tapright;

  bool mapheld;
  int menupage;
  int lastsaved;
  int deathcounts;

  int framecounter;
  bool seed_use_sdl_getticks;
  bool editor_disabled;
  int frames, seconds, minutes, hours;
  bool gamesaved;
  bool gamesavefailed;
  std::string savetime;
  int saveframes, saveseconds;
  int savetrinkets;
  bool startscript;
  std::string newscript;

  bool menustart;

  bool teleport_to_new_area;
  int teleport_to_x, teleport_to_y;
  std::string teleportscript;
  bool useteleporter;
  int teleport_to_teleporter;

  std::vector menuoptions;
  int currentmenuoption;
  bool menutestmode;
  enum MenuName currentmenuname;
  enum MenuName kludge_ingametemp;
  enum SLIDERMODE slidermode;
  int current_credits_list_index;
  int translator_credits_pagenum;
  int menuxoff, menuyoff;
  int menuspacing;
  std::vector menustack;

  int menucountdown;
  enum MenuName menudest;

  int creditposx, creditposy, creditposdelay;
  int oldcreditposx;

  SDL_GameControllerButton gpmenu_lastbutton;
  bool gpmenu_confirming;
  bool gpmenu_showremove;

  bool silence_settings_error;

  bool swnmode;
  enum SWNMODE swngame;
  int swnstate, swnstate2, swnstate3, swnstate4, swndelay, swndeaths;
  int swntimer, swncolstate, swncoldelay;
  int swnrecord, swnbestrank, swnrank, swnmessage;

  bool supercrewmate, scmhurt;
  int scmprogress;

  bool colourblindmode;
  bool noflashingmode;
  int slowdown;

  bool nodeathmode;
  int gameoverdelay;
  bool nocutscenes;
  int ndmresultcrewrescued;
  int ndmresulttrinkets;
  std::string ndmresulthardestroom;
  int ndmresulthardestroom_x;
  int ndmresulthardestroom_y;
  bool ndmresulthardestroom_specialname;

  bool intimetrial, timetrialparlost;
  int timetrialcountdown, timetrialshinytarget, timetriallevel;
  int timetrialpar, timetrialresulttime, timetrialresultframes, timetrialrank;
  bool timetrialcheater;
  int timetrialresultshinytarget, timetrialresulttrinkets, timetrialresultpar;
  int timetrialresultdeaths;

  bool start_translator_exploring;
  bool translator_exploring;
  bool translator_exploring_allowtele;
  bool translator_cutscene_test;

  size_t cutscenetest_menu_page;
  std::string cutscenetest_menu_play_id;

  int creditposition;
  int oldcreditposition;
  bool insecretlab;

  bool inintermission;

  bool crewstats[numcrew];
  bool ndmresultcrewstats[numcrew];

  bool alarmon;
  int alarmdelay;
  bool blackout;

#define numunlock 25

  bool unlock[numunlock];
  bool unlocknotify[numunlock];
  int stat_trinkets;
  int bestgamedeaths;

#define numtrials 6

  int besttimes[numtrials];
  int bestframes[numtrials];
  int besttrinkets[numtrials];
  int bestlives[numtrials];
  int bestrank[numtrials];

  int screenshake, flashlight;
  bool advancetext, pausescript;

  int deathseq, lifeseq;

  int savepoint, teleportxpos;
  bool teleport;
  int edteleportent;
  bool completestop;

  float inertia;

  int companion;
  SDL_Rect teleblock;
  bool activetele;
  int readytotele;
  int oldreadytotele;
  int activity_r, activity_g, activity_b, activity_y;
  std::string activity_lastprompt;
  bool activity_gettext;

  bool backgroundtext;

  int activeactivity, act_fade;
  int prev_act_fade;

  bool press_left, press_right, press_action, press_map, press_interact;
  bool interactheld;
  bool separate_interact;

  int totalflips;
  std::string hardestroom;
  int hardestroomdeaths, currentroomdeaths;
  int hardestroom_x, hardestroom_y;
  bool hardestroom_specialname;
  bool hardestroom_finalstretch;

  bool quickrestartkludge;

  std::string customscript[50];
  int customcol;
  int levelpage;
  int playcustomlevel;
  std::string customleveltitle;
  std::string customlevelfilename;

  std::map customlevelstats;

  std::vector controllerButton_map;
  std::vector controllerButton_flip;
  std::vector controllerButton_esc;
  std::vector controllerButton_restart;
  std::vector controllerButton_interact;

  bool skipfakeload;
  bool ghostsenabled;

  bool cliplaytest;
  int playx;
  int playy;
  int playrx;
  int playry;
  int playgc;
  int playmusic;
  std::string playassets;

  bool fadetomenu;
  int fadetomenudelay;
  bool fadetolab;
  int fadetolabdelay;

  bool over30mode;
  bool showingametimer;

  bool ingame_titlemode;
  bool ingame_editormode;

  bool disablepause;
  bool disableaudiopause;
  bool disabletemporaryaudiopause;
  bool inputdelay;

  bool statelocked;

  int old_skip_message_timer;
  int skip_message_timer;

  int old_mode_indicator_timer;
  int mode_indicator_timer;

  int old_screenshot_border_timer;
  int screenshot_border_timer;
  bool screenshot_saved_success;
};
