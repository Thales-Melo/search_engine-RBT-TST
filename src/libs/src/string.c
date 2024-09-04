#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/string.h"


String *string_construct(const char *c) {
    String *string = malloc(sizeof(String));
    if (string == NULL)
        exit(printf("Error string_construct: failed to allocate memory.\n"));
    string->len = strlen(c);
    string->c = malloc(string->len + 1);
    if (string->c == NULL)
        exit(printf("Error string_construct: failed to allocate memory.\n"));
    strcpy(string->c, c);
    return string;
}

void string_destruct(String *string) {
    if (string == NULL)
        return;
    free(string->c);
    free(string);
}

int compare_from(String *s, String *t, int d) {
    int min = s->len < t->len ? s->len : t->len;
    for (int i = d; i < min; i++) {
        if (s->c[i] < t->c[i]) { return -1; }
        if (s->c[i] > t->c[i]) { return 1; }
    }
    return s->len - t->len;
}

int compare(String *s, String *t) {
    return compare_from(s, t, 0);
}