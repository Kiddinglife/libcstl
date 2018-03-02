#include "../mycstl/cstl_types.h"
#include "cstl_types_builtin.h"

static const char* g_buildin_type_str[] =
{ "sint8t", "uint8t", "sint16t", "uint16t", "sint32t", "uint32t", "sint64t", "uint64t", "floatt", "doublet",
    "voidpointert",

    "vector_tt", "list_tt", "map_tt", "hash_tt", };

static const char* g_type_style_str[] =
{ "ctype", "cstltype", "userdefined", "userdefined", "invalidtype", };

/* the pt_type, pt_node and t_pos must be defined before use those macro */
#define register_type_start() type_t* pt_type
#define register_type(realtype, type, tstyle)\
    pt_type = (type_t*)malloc(sizeof(type_t));\
    pt_type->_t_typeid = _registered_type_count;\
    pt_type->_t_typesize = sizeof(realtype);\
    pt_type->_t_style = tstyle;\
    pt_type->_t_typeinit = _type_init_##type;\
    pt_type->_t_typecopy = _type_copy_##type;\
    pt_type->_t_typeless = _type_less_##type;\
    pt_type->_t_typedestroy = _type_destroy_##type;\
    _apt_bucket[_registered_type_count] = pt_type;\
    _registered_type_count++

/** local constant declaration and local macro section **/
static bool_t _t_isinit = false; /* is initializate for c and cstl built in types */
static unsigned char _registered_type_count = 0;
static type_t* _apt_bucket[TYPE_REGISTER_BUCKET_COUNT] =
{ 0 };

void mtype_init(void)
{
  register_type_start();
  register_type(char, char, ctype);
  register_type(char, uchar, ctype);
  register_type(short, short, ctype);
  register_type(unsigned short, ushort, ctype);
  register_type(int, int, ctype);
  register_type(int, uint, ctype);
  register_type(long, long, ctype);
  register_type(unsigned long, ulong, ctype);
  register_type(float, float, ctype);
  register_type(double, double, ctype);
  register_type(void*, pointer, ctype);

  //@TODO register cstl types

  for (int i = _registered_type_count; i < TYPE_REGISTER_BUCKET_COUNT; i++)
  {
    _apt_bucket[i] = NULL;
    printf("%x, ", _apt_bucket[i]);
  }
  _t_isinit = true;
}

static type_t* set_type_aux(int typeid)
{
  assert(typeid >=0 || typeid < TYPE_REGISTER_BUCKET_COUNT);
  if (!_t_isinit)
    mtype_init();
  return _apt_bucket[typeid];
}

type_t* set_type_info(type_info_t* typeinfo, const char* s_typename)
{
  if (!_t_isinit)
    mtype_init();

  // parse typename str and translate to typeid
  // vector<list<map<vector<int>, set<int>>>>
  int len;
  char buf[16];
  char* curr = buf;
  do
  {
    if (*s_typename != ' ')
    {
      if (*s_typename == '<')
      {
        *curr = '\0';
        len = strlen(buf);
        switch (len)
        {
        case 3: //int
          printf("int\n");
          break;
        case 4: //char long
          switch(curr[0])
          {
          case 'c': //char
            printf("char\n");
            break;
          case 'l': //long
            printf("long\n");
            break;
          default:
            perror("no such type\n");
            break;
          }
          break;
        case 5: //map_t set_t short
          break;
        case 6: //list_t
          break;
        case 7: //list_t deque_t stack_t queue_t
          break;
        case 8: //vector_t string_t
          break;
        case 9: //long long
          break;
        case 10: //hash_map_t multiset_t multimap_t hash_set_t
          break;
        case 12: //unsigned int
          break;
        case 13: //unsigned char unsigned long
          break;
        case 14: //unsigned short
          break;
        case 15: //hash_multimap_t hash_multiset_t
          break;
        case 16: // priority_queue_t
          break;
        case 18: //unsigned long long
          break;
        default:
          perror("no such type\n");
          break;
        }
        first = false;
      }
      else
      {
        *curr = *s_typename;
        curr++;
      }
    }
  } while (*s_typename++);
  assert(typeinfo->_t_typeids[0] >=0 || typeinfo->_t_typeids[0] < TYPE_REGISTER_BUCKET_COUNT);
  if (!_t_isinit)
    mtype_init();
  typeinfo->_t_type = _apt_bucket[typeinfo->_t_typeids[0]];
  return 0;
}
