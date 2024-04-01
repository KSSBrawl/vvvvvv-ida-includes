//
// from SDL2
//

#ifndef __SDL2__
#define __SDL2__

struct __declspec(align(4))
SDL_Rect
{
  int x;
  int y;
  int w;
  int h;
};

struct __declspec(align(1))
SDL_Color
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
};

#endif // __SDL2__
