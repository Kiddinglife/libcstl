#ifndef _CSTL_TYPES_AUX_H_
#define _CSTL_TYPES_AUX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "mycstl/cstl_types.h"

extern type_register_t  my_gt_typeregister;

/**
* Initialize the register and register c builtin type and cstl builtin type
*/
extern void mtype_init(void);

/**
* Caculate hash from type name.
* @param s_typename    type name.
* @return hash.
* @remarks s_typename must be not NULL.
*/
extern size_t _type_hash(const char* s_typename);

#ifdef __cplusplus
}
#endif
#endif /* _CSTL_TYPES_AUX_H_ */
/** eof **/