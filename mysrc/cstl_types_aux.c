#include "cstl_types_aux.h"
#include "cstl_types_builtin.h"

/* the pt_type, pt_node and t_pos must be defined before use those macro */
static void register_type_(int arr[], int tsize, int tid, int tstyle,
    bfun_t init, bfun_t cpy, bfun_t less, bfun_t destroy)
{
    type_t* pt_type = (type_t*)malloc(sizeof(type_t));

    int typeidsize = sizeof(arr);
    pt_type->_t_typeid_size = typeidsize;
    for (; typeidsize > 0; typeidsize--)
        pt_type->_t_typeids[typeidsize] = arr[typeidsize];

    pt_type->_t_typesize = tsize;
    pt_type->_t_typeid = tid;
    pt_type->_t_style = tstyle;
    pt_type->_t_typeinit = init;
    pt_type->_t_typecopy = cpy;
    pt_type->_t_typeless = less;
    pt_type->_t_typedestroy = destroy;

    _gt_typeregister._apt_bucket[_gt_typeregister._curr_size] = pt_type;
    _gt_typeregister._curr_size++;
}

#define register_type(type, type_, nativetype, ctype) \
    int arr##type##[] = { type }; \
    register_type_(arr##type,  sizeof(type_), type, ctype,\
        _type_init_##nativetype, _type_copy_##nativetype, _type_less_##nativetype,\
        _type_destroy_##nativetype)

/** local constant declaration and local macro section **/
extern type_register_t _gt_typeregister = { 0 };

void mtype_init(void)
{
    register_type(sint8t, char, char, ctype);
    register_type(sint16t, short, short, ctype);
    register_type(sint32t, int, int, ctype);
    register_type(uint8t, char, uchar, ctype);
    register_type(uint16t, unsigned short, ushort, ctype);
    register_type(uint32t, int, uint, ctype);
    register_type(floatt, float, float, ctype);
    register_type(doublet, double, double, ctype);
    register_type(voidpointert, void*, pointer, ctype);

    //@TODO register cstl types

    for (int i = _gt_typeregister._curr_size; i < TYPE_REGISTER_BUCKET_COUNT; i++)
        _gt_typeregister._apt_bucket[i] = NULL;
    _gt_typeregister._t_isinit = 1;
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
