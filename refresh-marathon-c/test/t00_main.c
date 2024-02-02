//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_printchar.c -o output
//./output

#include <unistd.h>

void mx_printchar(char c);

int main(void) {
    mx_printchar('A');
    mx_printchar('a');
    mx_printchar('!');
    mx_printchar(' ');
    mx_printchar('9');
    mx_printchar('\'');

    return 0;
}

