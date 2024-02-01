// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_binary_search.c mx_strcmp.c -o output
//./output

#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2);
int mx_binary_search(char **arr, int size, const char *s, int *count);


int main(void) {
    char* arr[6] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int size = 6, count = 0;
    const char *s = "z";

    for (int i = 0; i < size; i++)
        printf("\"%s\"\t", arr[i]);
    printf("\nsearch_string = \"%s\"\n", s);
    printf("mx_binary_search = %d\ncount = %d\n\n", mx_binary_search(arr, size, s, &count), count);

    s = "Test";
    for (int i = 0; i < size; i++)
        printf("\"%s\"\t", arr[i]);
    printf("\nsearch_string = \"%s\"\n", s);
    printf("mx_binary_search = %d\ncount = %d\n", mx_binary_search(arr, size, s, &count), count);

}

