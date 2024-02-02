//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_sqrt.c -o output
//./output

#include <stdio.h>
#include <math.h>

int mx_sqrt(int x);

int main(void) {
    int num = 16;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 4
    printf("sqrt=%f\n", sqrt(num));

    num = 4;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 2
    printf("sqrt=%f\n", sqrt(num));

    num = -10;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 0
    printf("sqrt=%f\n", sqrt(num));

    num = 38;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 0
    printf("sqrt=%f\n", sqrt(num));

    num = 0;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 0
    printf("sqrt=%f\n", sqrt(num));

    num = 1;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 1
    printf("sqrt=%f\n", sqrt(num));

    num = 100;
    printf("x=%d\tmx_sqrt=%d\t", num, mx_sqrt(num)); //returns 10
    printf("sqrt=%f\n", sqrt(num));

    return 0;
}

