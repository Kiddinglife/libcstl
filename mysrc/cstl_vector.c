/*
 * cstl_vector.c
 *
 *  Created on: 2 Mar. 2018
 *      Author: jackiez
 */

#ifndef MYSRC_CSTL_VECTOR_C_
#define MYSRC_CSTL_VECTOR_C_

#include "../mycstl/cstl_vector.h"

vector_t* _create_vector(const char* s_typename)
{
  vector_t* pvec_vector;
  /* allocate for vector_t and initialize it */
  if ((pvec_vector = (vector_t*) malloc(sizeof(vector_t))) == NULL)
    return NULL;
  if (!_create_vector_auxiliary(pvec_vector, s_typename)) {
      free(pvec_vector);
      return NULL;
  }
  return pvec_vector;
}

static bool_t _create_vector_auxiliary(vector_t* pvec_vector, const char* s_typename)
{
  return false;
}
#endif /* MYSRC_CSTL_VECTOR_C_ */
