//
// from vvvvvv/Tower.h
//

struct __declspec(align(4))
towerclass
{
  short back[40 * 120];
  short contents[40 * 700];
  short minitower[40 * 100];

  bool minitowermode;
};
