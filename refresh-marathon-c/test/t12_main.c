// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_factorial_iter.c -o output
//./output

#include <stdio.h>
#include <limits.h>

int mx_factorial_iter(int n);

int main(void) {
    printf("INT_MAX=%d\n", INT_MAX);

    printf("(-13)!=%d\n", mx_factorial_iter(-13)); // returns 0
    printf("(-0)!=%d\n", mx_factorial_iter(-0)); // returns 1
    printf("2!=%d\n", mx_factorial_iter(2)); // returns 2
    printf("5!=%d\n", mx_factorial_iter(5)); // returns 120
    printf("(+10)!=%d\n", mx_factorial_iter(+10)); // returns 3628800
    printf("12!=%d\n", mx_factorial_iter(12)); // returns 479001600
    printf("16!=%d\n", mx_factorial_iter(16)); // returns 0
    printf("25!=%d\n", mx_factorial_iter(25)); // returns 0

    return 0;
}

