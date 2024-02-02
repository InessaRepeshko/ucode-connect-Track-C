//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_strcpy.c -o output
//./output

#include <stdio.h>

char *mx_strcpy(char *dst, const char *src);

int main(void) {
    char dst[6] = "First";
    char src[10] = "Second";
    
    printf("initial dst=%s\n", dst);
    printf("changed dst=%s\n", mx_strcpy(dst, src));
}

