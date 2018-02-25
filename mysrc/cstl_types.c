#include "mysrc/cstl_types_aux.h"

void mtype_get_type(type_t* pt_typeinfo, const char* s_typename)
{
    assert(pt_typeinfo != NULL);
    assert(s_typename != NULL);
    char s_registered_name[TYPE_NAME_SIZE + 1];

    if (!_gt_typeregister._t_isinit) 
       mtype_init();
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