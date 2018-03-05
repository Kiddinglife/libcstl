/*
 * cstl_vector.h
 *
 *  Created on: 2 Mar. 2018
 *      Author: jackiez
 */

#ifndef MYCSTL_CSTL_VECTOR_H_
#define MYCSTL_CSTL_VECTOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "../mycstl/cstl_types.h"

/*
 * vector_t
 * _pby_start          _pby_finish      _pby_endofstorage
 * |                     |               |
 * V                     V               V
 * +-------------------------------------+
 * |    ... data ...     |               |
 * +-------------------------------------+
 * |<--------size()----->|
 * |<---------------capacity()---------->|
 */
typedef struct _tagvector
{
  /* element type information */
  type_info_t _t_typeinfo;
  /* vector core struct pointer */
  _byte_t* _pby_start; /* the start of used space */
  _byte_t* _pby_finish; /* the end of used space */
  _byte_t* _pby_endofstorage; /* the end of capacity space */
} vector_t;

/**
 * Create vector container.
 * @param s_typename element type name.
 * @return if create vector successfully, then return vector pointer, else return NULL.
 * @remarks if s_typename == NULL, then the behavior is undefined. s_typename should be C builtin type name,
 *          libcstl builtin typename or registed user defined type name, otherwise the function will return NULL.
 */
extern vector_t* create_vector(int size, ...);

#ifdef __cplusplus
}
#endif

#endif /* MYCSTL_CSTL_VECTOR_H_ */
