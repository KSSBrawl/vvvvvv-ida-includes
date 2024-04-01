//
// from STL
//

struct __declspec(align(1))
std::binary_function
{
  unsigned char _; // empty structs in C have size 0, but this is for a C++ program where empty structs are size 1
};

enum _Rb_tree_color { _S_red = false, _S_black = true };

struct __declspec(align(8))
std::_Rb_tree_node_base
{
  _Rb_tree_color _M_color;
  void *_M_parent;
  void *_M_left;
  void *_M_right;
};

struct __declspec(align(8))
std::map
{
  std::binary_function _M_key_compare;
  std::_Rb_tree_node_base _M_header;
  size_t _M_node_count;
};

struct __declspec(align(8))
std::string
{
  struct _Alloc_hider
  {
    char *_M_p;
  } _M_dataplus;
  
  size_t _M_string_length;

#define _S_local_capacity 15
  union
  {
    char _M_local_buf[_S_local_capacity + 1];
    size_t _M_allocated_capacity;
  };
};

struct __declspec(align(8))
std::vector
{
  void *_M_start;
  void *_M_finish;
  void *_M_end_of_storage;
};
