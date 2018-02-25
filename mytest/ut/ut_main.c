/*
* libcst unit test main function.
*/
#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include "../google/cmockery.h"
#include <time.h>

#include "ut_cstl_types.h"

int main(int argc, char* argv[])
{
    const UnitTest tests[] =
    {
         UT_CSTL_TYPES_CASE
    };
    return run_tests(tests);
}
