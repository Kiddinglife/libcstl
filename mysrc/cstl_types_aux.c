#include "cstl_types_aux.h"
#include "cstl_types_builtin.h"

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

static void mtype_init(void)
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
