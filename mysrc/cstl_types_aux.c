#include "cstl_types_aux.h"
#include "cstl_types_builtin.h"

/** local constant declaration and local macro section **/
/* the pt_type, pt_node and t_pos must be defined before use those macro */
#define TYPE_REGISTER_BEGIN() type_node_t* pt_node;type_t* pt_type; size_t t_pos = 0
#define REGISTER_TYPE(type, type_text, type_suffix, type_style)\
    do { \
        pt_type = (type_t*)malloc(sizeof(type_t)); \
        assert(pt_type != NULL); \
        pt_type->_t_typesize = sizeof(type); \
        memset(pt_type->_s_typename, '\0', TYPE_NAME_SIZE + 1); \
        strncpy(pt_type->_s_typename, type_text, TYPE_NAME_SIZE); \
        assert(type_style != TYPE_INVALID); \
        pt_type->_t_style = type_style; \
        pt_type->_t_typeinit = _type_init_##type_suffix; \
        pt_type->_t_typecopy = _type_copy_##type_suffix;\
        pt_type->_t_typeless = _type_less_##type_suffix;\
        pt_type->_t_typedestroy = _type_destroy_##type_suffix;\
    }while(false);

#define REGISTER_TYPE_NODE(type, type_text)\
    do{\
        pt_node = (type_node_t*)malloc(sizeof(type_node_t));\
        assert(pt_node != NULL);\
        memset(pt_node->_s_typename, '\0', TYPE_NAME_SIZE + 1);\
        strncpy(pt_node->_s_typename, type_text, TYPE_NAME_SIZE);\
        /*t_pos = _type_hash(type_text);\*/ \
        t_pos = _gt_typeregister._curr_size; \
        /*pt_node->_pt_next = _gt_typeregister._apt_bucket[t_pos];\*/ \
        _gt_typeregister._curr_size ++;\
        _gt_typeregister._apt_bucket[t_pos] = pt_node;\
        pt_node->_pt_type = pt_type;\
    } while (false);

extern type_register_t _gt_typeregister = { 0 };

void mtype_init(void)
{
    size_t i = 0;
    for (i = 0; i < TYPE_REGISTER_BUCKET_COUNT; ++i) {
        _gt_typeregister._apt_bucket[i] = NULL;
    }
    //_type_register_c_builtin();
    //_type_register_cstl_builtin();
    _gt_typeregister._t_isinit = 1;
}

void mtype_register_c_builtin(void)
{
    TYPE_REGISTER_BEGIN();
    REGISTER_TYPE(char, _CHAR_TYPE, char, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(char, _CHAR_TYPE);
    REGISTER_TYPE_NODE(signed char, _SIGNED_CHAR_TYPE);
    /* register unsigned char */
    REGISTER_TYPE(unsigned char, _UNSIGNED_CHAR_TYPE, uchar, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(unsigned char, _UNSIGNED_CHAR_TYPE);
    /* register short */
    REGISTER_TYPE(short, _SHORT_TYPE, short, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(short, _SHORT_TYPE);
    REGISTER_TYPE_NODE(short int, _SHORT_INT_TYPE);
    REGISTER_TYPE_NODE(signed short, _SIGNED_SHORT_TYPE);
    REGISTER_TYPE_NODE(signed short int, _SIGNED_SHORT_INT_TYPE);
    /* register unsigned short */
    REGISTER_TYPE(unsigned short, _UNSIGNED_SHORT_TYPE, ushort, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(unsigned short, _UNSIGNED_SHORT_TYPE);
    REGISTER_TYPE_NODE(unsigned short int, _UNSIGNED_SHORT_INT_TYPE);
    /* register int */
    REGISTER_TYPE(int, _INT_TYPE, int, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(int, _INT_TYPE);
    REGISTER_TYPE_NODE(signed, _SIGNED_TYPE);
    REGISTER_TYPE_NODE(signed int, _SIGNED_INT_TYPE);
    /* register unsigned int */
    REGISTER_TYPE(unsigned int, _UNSIGNED_INT_TYPE, uint, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(unsigned int, _UNSIGNED_INT_TYPE);
    REGISTER_TYPE_NODE(signed, _UNSIGNED_TYPE);
    /* register long */
    REGISTER_TYPE(long, _LONG_TYPE, long, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(long, _LONG_TYPE);
    REGISTER_TYPE_NODE(long int, _LONG_INT_TYPE);
    REGISTER_TYPE_NODE(signed long, _SIGNED_LONG_TYPE);
    REGISTER_TYPE_NODE(signed long int, _SIGNED_LONG_INT_TYPE);
    /* register unsigned long */
    REGISTER_TYPE(unsigned long, _UNSIGNED_LONG_TYPE, ulong, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(unsigned long, _UNSIGNED_LONG_TYPE);
    REGISTER_TYPE_NODE(unsigned long int, _UNSIGNED_LONG_INT_TYPE);
    /* register float */
    REGISTER_TYPE(float, _FLOAT_TYPE, float, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(float, _FLOAT_TYPE);
    /* register double */
    REGISTER_TYPE(double, _DOUBLE_TYPE, double, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(double, _DOUBLE_TYPE);
    /* register long double */
    REGISTER_TYPE(long double, _LONG_DOUBLE_TYPE, long_double, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(long double, _LONG_DOUBLE_TYPE);
    /* register bool_t */
    REGISTER_TYPE(bool_t, _CSTL_BOOL_TYPE, cstl_bool, TYPE_C_BUILTIN);
    REGISTER_TYPE_NODE(bool_t, _CSTL_BOOL_TYPE);
}
void mtype_register_cstl_builtin(void)
{

}

/* BKDR hash seed */
#define TYPE_HASH_BKDR_SEED    131
size_t _type_hash(const char* s_typename)
{
    size_t t_hash = 0;
    assert(s_typename != NULL);
    while (*s_typename)
        t_hash = t_hash * TYPE_HASH_BKDR_SEED + (*s_typename++);
    return t_hash % TYPE_REGISTER_BUCKET_COUNT;
}
