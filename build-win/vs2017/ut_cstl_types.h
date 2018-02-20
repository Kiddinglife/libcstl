#ifndef _UT_CSTL_TYPES_H_
#define _UT_CSTL_TYPES_H_

#include "ut_def.h"

UT_SUIT_DECLARATION(cstl_types)

/*
* test _type_init_default
*/
UT_CASE_DECLARATION(_type_init_default)
void test__type_init_default__null_input(void** state);
//void test__type_init_default__null_output(void** state);
//void test__type_init_default__ok(void** state);

#define UT_CSTL_TYPES_CASE \
    UT_SUIT_BEGIN(cstl_types, test__type_init_default__null_input),
    //UT_CASE(test__type_init_default__null_output), \
    //UT_CASE(test__type_init_default__ok), 

#endif

