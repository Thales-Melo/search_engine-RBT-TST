#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "../include/utils.h"

void string_to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}