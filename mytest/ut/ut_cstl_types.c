#include "ut_cstl_types.h"
#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <google/cmockery.h>

// file name + test case name
UT_SUIT_DEFINATION(cstl_types, _type_init_default)

/*
* test _type_init_default
*/
UT_CASE_DEFINATION(_type_init_default)
void test__type_init_default__null_input(void** state)
{
    size_t output = 0;
   //expect_assert_failure(_type_init_default(NULL, &output));
    printf("test__type_init_default__null_input()");
}