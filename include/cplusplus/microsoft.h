//
// from STL
//

struct __declspec(align(1))
std::allocator
{
  unsigned char _; // empty structs in C have size 0, but this is for a C++ program where empty structs are size 1
};

struct __declspec(align(1))
std::less
{
  unsigned char _; // empty structs in C have size 0, but this is for a C++ program where empty structs are size 1
};

struct __declspec(align(4))
std::map
{
  std::less comp;
  void *_Myhead;
  size_t _Mysize;
  std::allocator _Alnod;
  std::allocator _Alval;
};

struct __declspec(align(4))
std::string
{
#define _BUF_SIZE 16

  union
  {
    char _Buf[_BUF_SIZE];
    char *_Ptr;
    char _Alias[_BUF_SIZE];
  }_Bx;

  size_t _Mysize;
  size_t _Myres;
  std::allocator _Alval;
};

struct __declspec(align(4))
std::vector
{
  void *_Myfirst;
  void *_Mylast;
  void *_Myend;
  std::allocator _Alval;
};
