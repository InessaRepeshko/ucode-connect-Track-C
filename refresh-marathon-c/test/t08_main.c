//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_strcmp.c -o output
//./output

#include <stdio.h>
#include <string.h>

int mx_strcmp(const char *s1, const char *s2);

int main(void) {
    const char *str1 = "Hello";
    const char *str2 = "hello";
    const char *str3 = "World";

    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n", str1, str2, mx_strcmp(str1, str2), strcmp(str1, str2));
    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n\n", str1, str3, mx_strcmp(str1, str3), strcmp(str1, str3));

    str1 = "english";
    str2 = "eng";
    str3 = "World";

    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n", str1, str2, mx_strcmp(str1, str2), strcmp(str1, str2));
    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n\n", str1, str3, mx_strcmp(str1, str3), strcmp(str1, str3));


    return 0;
}

