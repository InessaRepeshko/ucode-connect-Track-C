// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_strdup.c mx_strlen.c mx_strnew.c mx_strcpy.c -o output
//./output

#include <stdio.h>
#include <string.h>

int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);

int main(void) {
    const char *str1 = "What's up, Neo?";
    printf("mx_strdup:\tstr=\"%s\"\tdst=\"%s\"\n", str1, mx_strdup(str1));
    printf("strdup:\t\tstr=\"%s\"\tdst=\"%s\"\n\n", str1, strdup(str1));


    const char *str2 = "test\'!\"@#92%^&*;";
    printf("mx_strdup:\tstr=\"%s\"\tdst=\"%s\"\n", str2, mx_strdup(str2));
    printf("strdup:\t\tstr=\"%s\"\tdst=\"%s\"\n", str2, strdup(str2));

}

