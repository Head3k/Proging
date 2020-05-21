#include <stdio.h>

typedef struct {
    char str[3];
    int num;
} NumberRepr;

void format(NumberRepr* number)
{
    snprintf(number->str, 4, "%3d", number->num);
}

int main()
{
    NumberRepr number = {.num = 1025};
    format(&number);
    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num);
    return 0;
}

