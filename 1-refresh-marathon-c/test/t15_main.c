// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_strnew.c -o output
//./output

#include <stdio.h>
#include <string.h>

char *mx_strnew(const int size);

int main(void) {
//    printf("size=-1, len=%lu, str=\"%s\"\n",
//           strlen(mx_strnew(-10)), mx_strnew(-10)); //returns zsh: segmentation fault  ./output
    printf("size=0, len=%lu, str=\"%s\"\n",
           strlen(mx_strnew(0)), mx_strnew(0)); // returns size=0, len=0, str=""
    printf("size=3, len=%lu, str=\"%s\"\n",
           strlen(mx_strnew(3)), mx_strnew(3)); // retirns size=3, len=0, str=""
}

