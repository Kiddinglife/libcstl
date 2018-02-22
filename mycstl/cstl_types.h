#ifndef _CSTL_TYPES_H_
#define _CSTL_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "mycstl/cstl_def.h"

    /* c built-in type */
#define _CHAR_TYPE                      "char"
#define _SIGNED_CHAR_TYPE               "signed char"

#define _UNSIGNED_CHAR_TYPE             "unsigned char"

#define _SIGNED_SHORT_INT_TYPE          "signed short int"
#define _SIGNED_SHORT_TYPE              "signed short"
#define _SHORT_INT_TYPE                 "short int"
#define _SHORT_TYPE                     "short"

#define _UNSIGNED_SHORT_INT_TYPE        "unsigned short int"
#define _UNSIGNED_SHORT_TYPE            "unsigned short"

#define _INT_TYPE                       "int"
#define _SIGNED_TYPE                    "signed"
#define _SIGNED_INT_TYPE                "signed int"

#define _UNSIGNED_INT_TYPE              "unsigned int"
#define _UNSIGNED_TYPE                  "unsigned"

#define _LONG_TYPE                      "long"
#define _LONG_INT_TYPE                  "long int"
#define _SIGNED_LONG_TYPE               "signed long"
#define _SIGNED_LONG_INT_TYPE           "signed long int"

#define _UNSIGNED_LONG_TYPE             "unsigned long"
#define _UNSIGNED_LONG_INT_TYPE         "unsigned long int"

#define _FLOAT_TYPE                     "float"
#define _DOUBLE_TYPE                    "double"
#define _LONG_DOUBLE_TYPE               "long double"

#define _C_STRING_TYPE                  "char*"
#define _POINTER_TYPE                   "void*"

#define _CSTL_BOOL_TYPE                 "bool_t"
#define _BOOL_TYPE                      "_Bool"

#define _LONG_LONG_TYPE                 "long long"
#define _LONG_LONG_INT_TYPE             "long long int"
#define _SIGNED_LONG_LONG_TYPE          "signed long long"
#define _SIGNED_LONG_LONG_INT_TYPE      "signed long long int"

#define _UNSIGNED_LONG_LONG_TYPE        "unsigned long long"
#define _UNSIGNED_LONG_LONG_INT_TYPE    "unsigned long long int"
    /* cstl type */
#define _VECTOR_TYPE                    "vector_t"
#define _LIST_TYPE                      "list_t"
#define _SLIST_TYPE                     "slist_t"
#define _DEQUE_TYPE                     "deque_t"
#define _STACK_TYPE                     "stack_t"
#define _QUEUE_TYPE                     "queue_t"
#define _PRIORITY_QUEUE_TYPE            "priority_queue_t"
#define _SET_TYPE                       "set_t"
#define _MAP_TYPE                       "map_t"
#define _MULTISET_TYPE                  "multiset_t"
#define _MULTIMAP_TYPE                  "multimap_t"
#define _HASH_SET_TYPE                  "hash_set_t"
#define _HASH_MAP_TYPE                  "hash_map_t"
#define _HASH_MULTISET_TYPE             "hash_multiset_t"
#define _HASH_MULTIMAP_TYPE             "hash_multimap_t"
#define _STRING_TYPE                    "string_t"
#define _PAIR_TYPE                      "pair_t"
#define _RANGE_TYPE                     "range_t"
#define _BASIC_STRING_TYPE              "basic_string_t"

    /* cstl iterator type */
#define _ITERATOR_TYPE                  "iterator_t"
#define _VECTOR_ITERATOR_TYPE           "vector_iterator_t"
#define _LIST_ITERATOR_TYPE             "list_iterator_t"
#define _SLIST_ITERATOR_TYPE            "slist_iterator_t"
#define _DEQUE_ITERATOR_TYPE            "deque_iterator_t"
#define _SET_ITERATOR_TYPE              "set_iterator_t"
#define _MAP_ITERATOR_TYPE              "map_iterator_t"
#define _MULTISET_ITERATOR_TYPE         "multiset_iterator_t"
#define _MULTIMAP_ITERATOR_TYPE         "multimap_iterator_t"
#define _HASH_SET_ITERATOR_TYPE         "hash_set_iterator_t"
#define _HASH_MAP_ITERATOR_TYPE         "hash_map_iterator_t"
#define _HASH_MULTISET_ITERATOR_TYPE    "hash_multiset_iterator_t"
#define _HASH_MULTIMAP_ITERATOR_TYPE    "hash_multimap_iterator_t"
#define _STRING_ITERATOR_TYPE           "string_iterator_t"
#define _INPUT_ITERATOR_TYPE            "input_iterator_t"
#define _OUTPUT_ITERATOR_TYPE           "output_iterator_t"
#define _FORWARD_ITERATOR_TYPE          "forward_iterator_t"
#define _BIDIRECTIONAL_ITERATOR_TYPE    "bidirectional_iterator_t"
#define _RANDOM_ACCESS_ITERATOR_TYPE    "random_access_iterator_t"
#define _BASIC_STRING_ITERATOR_TYPE     "basic_string_iterator_t"

    /* structure type */
#define _STRUCT_TYPE                    "struct"
#define _UNION_TYPE                     "union"
#define _ENUM_TYPE                      "enum"

    /* cstl container type */
#define _CSTL_LEFT_BRACKET              '<'
#define _CSTL_RIGHT_BRACKET             '>'
#define _CSTL_COMMA                     ','
#define _CSTL_POINTER                   '*'

    /*
    * Type definition of unary function and binary function.
    * Note: The last parameter is for output
    */
    typedef void(*unary_function_t)(const void* in, void* out);
    typedef void(*binary_function_t)(const void* in, const void* in_, void* out);
    typedef unary_function_t  ufun_t;
    typedef binary_function_t bfun_t;

#define TYPE_NAME_SIZE              255
    typedef enum
    {
        TYPE_INVALID = 0,
        TYPE_C_BUILTIN,
        TYPE_USER_DEFINE,
        TYPE_CSTL_BUILTIN
    }tagtypestyle;

    typedef struct
    {
        int                   _t_typeid;
        size_t               _t_typesize;                        /* type size */
        char                 _s_typename[TYPE_NAME_SIZE + 1];   /* type name */
        tagtypestyle         _t_style;                           /* type style */
        bfun_t               _t_typecopy;                        /* type copy function */
        bfun_t               _t_typeless;                        /* type less function */
        ufun_t               _t_typeinit;                        /* type initialize function */
        ufun_t               _t_typedestroy;                     /* type destroy function */
    }type_t;

    typedef struct
    {
        int                   _t_typeid;
        char                 _s_typename[TYPE_NAME_SIZE + 1];
        type_t*             _pt_type;
        tagtypestyle         _t_style;
    }type_info_t;

    typedef struct type_node_t_def
    {
        int                   _t_typeid;
        char                 _s_typename[TYPE_NAME_SIZE + 1];   /* type name */
        struct type_node_t_def* _pt_next;                           /* next node */
        type_t*             _pt_type;                           /* the registered type */
    }type_node_t;

#define TYPE_REGISTER_BUCKET_COUNT  997   /* register hash table bucket count */
    typedef struct 
    {
        int               _t_isinit; /* is initializate for built in types */
        int _curr_size;
        type_node_t*         _apt_bucket[TYPE_REGISTER_BUCKET_COUNT]; /* hash table */
    }type_register_t;

    extern void mtype_get_type(type_info_t* pt_typeinfo, const char* s_typename);


#ifdef __cplusplus
}
#endif
#endif /* _CSTL_TYPES_H_ */