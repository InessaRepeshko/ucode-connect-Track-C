// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_foreach.c -o output
//./output

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mx_foreach(int *arr, int size, void (*f)(int));

void mx_printchar(char c) {
    write(1, &c, 1);
}

void mx_printint(int n) {
    long num = n;

    if (num < 0) {
        mx_printchar('-');
        num *= -1;
    }

    if (num > 9)
        mx_printint(num / 10); //recursion
    mx_printchar(num % 10 + 48);
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
    mx_foreach(arr, 5, mx_printint); //prints "12345" to the standart output
    printf("\n\n");
//    system("leaks -q res");
}

