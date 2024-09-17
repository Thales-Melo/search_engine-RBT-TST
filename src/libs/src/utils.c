#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "../include/utils.h"
#include "../include/page.h"


void string_to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

double fabs(double x) {
    if (x < 0)      return -x;
    else            return x;
}

void apply_to_all_pages(RBT *pages, Func function, void *argument) {
    RBTIterator *it = RBT_iterator_construct(pages);
    while (RBT_iterator_valid(it)) {
        Page *page = (Page *)RBT_iterator_value(it);
        function(page, argument);
        RBT_iterator_next(it);
    }
    RBT_iterator_destruct(it);
}

void remove_newline(char *str) {
    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}