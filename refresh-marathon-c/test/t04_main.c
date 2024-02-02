//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_printint.c mx_printchar.c -o output
//./output

#include <unistd.h>

void mx_printint(int n);

int main (void) {
    long n1 = -2147483649;
    mx_printint(n1); // returns 2147483647
    write(1, "\n", 1);

    long n2 = 2147483649;
    mx_printint(n2); // returns -2147483647
    write(1, "\n", 1);
    
    long n3 = -0;
    mx_printint(n3); // returns 0
    write(1, "\n", 1);

    long n4 = -2147483648;
    mx_printint(n4); // returns -2147483648
    write(1, "\n", 1);

    long n5 = 2147483648;
    mx_printint(n5); // returns -2147483648
    write(1, "\n", 1);

    long n6 = 987654321;
    mx_printint(n6); // returns 987654321
    write(1, "\n", 1);

    return 0;
}

