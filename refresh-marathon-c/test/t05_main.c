//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_pow.c -o output
//./output

#include <stdio.h>
#include <math.h>

double mx_pow(double n, unsigned int pow);

int main(void) {
    double num = 2.5;
    unsigned int power = 3;
    printf("mx_pow=%f\n", mx_pow(num, power));
    printf("pow=%f\n\n", pow(num, power));

    printf("mx_pow=%f\n", mx_pow(3, 3)); //returns 27
    printf("pow=%f\n\n", pow(3, 3));

    printf("mx_pow=%f\n", mx_pow(2.5, 3)); //returns 15.625
    printf("pow=%f\n\n", pow(2.5, 3));

    printf("mx_pow=%f\n", mx_pow(2, 0)); //returns 1
    printf("pow=%f\n\n", pow(2, 0));

    printf("mx_pow=%f\n", mx_pow(-3, 3)); //returns -27
    printf("pow=%f\n\n", pow(-3, 3));

    printf("mx_pow=%f\n", mx_pow(8, 0)); //returns 1
    printf("pow=%f\n\n", pow(8, 0));

    printf("mx_pow=%f\n", mx_pow(0, 5)); //returns 0
    printf("pow=%f\n\n", pow(0, 5));

    return 0;
}

