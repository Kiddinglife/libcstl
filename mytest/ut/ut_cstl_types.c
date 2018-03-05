#include "ut_cstl_types.h"
#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <google/cmockery.h>
#include "mycstl/cstl_vector.h"

// file name + test case name
UT_SUIT_DEFINATION(cstl_types, mtype_register_c_builtin)

/*
* test _type_init_default
*/
UT_CASE_DEFINATION(mtype_register_c_builtin)
void test_mtype_register_c_builtin(void** state)
{
    size_t output = 0;
    show_registered_types();
    create_vector(2, cstl_int32);
   // expect_assert_failure(_type_init_default(NULL, &output));
}