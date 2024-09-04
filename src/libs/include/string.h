#if !defined(_STRING_H_)
#define _STRING_H_

typedef struct String String;
struct String {
    char *c;
    int len;
};


String *string_construct(const char *c);

void string_destruct(String *string);

int compare_from(String *s, String *t, int d);

int compare(String *s, String *t);

#endif // _STRING_H_
