//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_strlen.c -o output
//./output

#include <stdio.h>
#include <string.h>


int mx_strlen(const char *s);

int main(void) {
    const char *str = "Hello, World!";
    printf("Length of the string \"%s\" is %d.\n", str, mx_strlen(str));
    printf("Length of the string \"%s\" is %lu.\n", str, strlen(str));
    return 0;
}

