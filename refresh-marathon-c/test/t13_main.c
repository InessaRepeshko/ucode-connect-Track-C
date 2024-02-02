// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_bubble_sort.c mx_strcmp.c -o output
//./output

#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2);
int mx_bubble_sort(char **arr, int size);

int main(void) {
    char *arr1[] = {"abc", "acb", "a"};
    for (int i = 0; i < 3; i++)
        printf("%s\t", arr1[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr1, 3)); // returns 2
    for (int i = 0; i < 3; i++)
        printf("%s\t", arr1[i]);
    printf("\n\n");
    
    char *arr2[] = {"abc", "xyz", "ghi", "def"};
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr2[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr2, 4)); //returns 3
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr2[i]);
    printf("\n\n");

    char *arr3[] = {"456", "412", "987", "123"};
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr3[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr3, 4)); //returns 4
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr3[i]);
    printf("\n\n");

    char *arr4[] = {"12", "34", "56", "78"};
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr4[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr4, 4)); //returns 0
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr4[i]);
    printf("\n");
}

