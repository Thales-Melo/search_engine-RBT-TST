#if !defined(_UTILS_H_)
#define _UTILS_H_

#include "rbt.h"
#include "types.h"

void string_to_lower(char *str);
void apply_to_all_pages(RBT *pages, Func function, void *argument);
double fabs(double x);
#endif // _UTILS_H_)
