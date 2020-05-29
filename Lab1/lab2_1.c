#include <stdio.h>

typedef struct {   // init struct "NumberRepr"
    char str[5];  // 
    int num;     //
} NumberRepr;   //

void format(NumberRepr* number) {               // init format
    sprintf(number->str, "%4d", number->num);  //  
}                                             // 

int main() {                               // 
    NumberRepr number = { .num = 1025 };  // 
    format(&number);                     // use void "format"
    printf("str: %s\n", number.str);    // print number.str
    printf("num: %d\n", number.num);   // print number.num
    return 0;                         //
}

