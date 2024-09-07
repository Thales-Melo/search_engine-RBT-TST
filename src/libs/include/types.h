#if !defined(_TYPES_H_)
#define _TYPES_H_

#include <stdbool.h>

#define Value void*
#define NULL_Value NULL
#define SPECIAL_NULL_VALUE ((void*)1) // Diferenciar de NULL_Value

#define RED true
#define BLACK false
typedef int (*CompareFunc)(const char *v1, const char *v2);
typedef void (*Func)(void *value, void *argument);;

#endif // _TYPES_H_)
