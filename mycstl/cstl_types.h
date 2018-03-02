#ifndef _CSTL_TYPES_H_
#define _CSTL_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "../mycstl/cstl_def.h"

    // user can override this
#define TYPE_NAME_SIZE 255
#define TYPE_REGISTER_BUCKET_COUNT  64
#define TYPE_ID_SIZE              8

    enum
    {
        sint8t,
        uint8t,
        sint16t,
        uint16t,
        sint32t,
        uint32t,
        sint64t,
        uint64t,
        floatt,
        doublet,
        voidpt,

        vector_tt,
        list_tt,
        map_tt,
        hash_tt,
    };

    enum
    {
        ctype,
        cstltype,
        userdefined,
        invalidtype
    };

    /*
    * Type definition of unary function and binary function.
    * Note: The last parameter is for output
    */
    typedef void(*unary_function_t)(const void* in, void* out);
    typedef void(*binary_function_t)(const void* in, const void* in_, void* out);
    typedef unary_function_t  ufun_t;
    typedef binary_function_t bfun_t;

    typedef struct
    {
        unsigned char        _t_typeid;
        unsigned short       _t_typesize;                        /* type size */
        unsigned char        _t_style;                           /* type style */
        bfun_t               _t_typecopy;                        /* type copy function */
        bfun_t               _t_typeless;                        /* type less function */
        ufun_t               _t_typeinit;                        /* type initialize function */
        ufun_t               _t_typedestroy;                     /* type destroy function */
    }type_t;

    typedef struct
    {
        unsigned char        _t_typeids[TYPE_ID_SIZE];
        type_t*              _t_type;
    }type_info_t;

    extern type_t*  mtype_get_type(const char* s_typename);

#ifdef __cplusplus
}
#endif
#endif /* _CSTL_TYPES_H_ */
