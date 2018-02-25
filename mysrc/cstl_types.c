#include "../mycstl/cstl_types.h"
#include "cstl_types_builtin.h"

static const char* g_buildin_type_str[] =
{
    "sint8t",
    "uint8t",
    "sint16t",
    "uint16t",
    "sint32t",
    "uint32t",
    "sint64t",
    "uint64t",
    "floatt",
    "doublet",
    "voidpointert",

    "vector_tt",
    "list_tt",
    "map_tt",
    "hash_tt",
};

static const char* g_type_style_str[] =
{
    "ctype",
    "cstltype",
    "userdefined",
    "userdefined",
    "invalidtype",
};

/* the pt_type, pt_node and t_pos must be defined before use those macro */
#define register_type_start() type_t* pt_type
#define register_type(realtype, type, tstyle)\
    pt_type = (type_t*)malloc(sizeof(type_t));\
    pt_type->_t_typeid = my_gt_typeregister._curr_size;\
    pt_type->_t_typesize = sizeof(realtype);\
    pt_type->_t_style = tstyle;\
    pt_type->_t_typeinit = _type_init_##type;\
    pt_type->_t_typecopy = _type_copy_##type;\
    pt_type->_t_typeless = _type_less_##type;\
    pt_type->_t_typedestroy = _type_destroy_##type;\
    my_gt_typeregister._apt_bucket[my_gt_typeregister._curr_size] = pt_type;\
    my_gt_typeregister._curr_size++

/** local constant declaration and local macro section **/
static type_register_t my_gt_typeregister = { 0 };

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

    for (int i = my_gt_typeregister._curr_size; i < TYPE_REGISTER_BUCKET_COUNT; i++)
        my_gt_typeregister._apt_bucket[i] = NULL;
    my_gt_typeregister._t_isinit = 1;
}

type_t*  mtype_get_type(int typeid)
{
    if (!my_gt_typeregister._t_isinit) 
       mtype_init();
    return  my_gt_typeregister._apt_bucket[typeid];
}

/* default copy, less, and destroy function */
void _type_init_default(const void* cpv_input, void* pv_output)
{
    assert(cpv_input != NULL && pv_output != NULL);
    memset((void*)cpv_input, 0x00, *(size_t*)pv_output);
    *(bool_t*)pv_output = true;
}
void _type_copy_default(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    assert(cpv_first != NULL && cpv_second != NULL && pv_output != NULL);
    memcpy((void*)cpv_first, cpv_second, *(size_t*)pv_output);
    *(bool_t*)pv_output = true;
}
void _type_less_default(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    assert(cpv_first != NULL && cpv_second != NULL && pv_output != NULL);
    *(bool_t*)pv_output = memcmp(cpv_first, cpv_second, *(size_t*)pv_output) < 0 ? true : false;
}
void _type_destroy_default(const void* cpv_input, void* pv_output)
{
    void* pv_avoidwarning = NULL;
    assert(cpv_input != NULL && pv_output != NULL);
    pv_avoidwarning = (void*)cpv_input;
    *(bool_t*)pv_output = true;
}