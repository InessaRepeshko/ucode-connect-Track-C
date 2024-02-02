//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_sort_arr_int.c -o output
//./output

#include <stdio.h>

void mx_sort_arr_int(int *arr, int size);

int main(void) {
    int array[] = {3, 55, -11, 1, 0, 4, 22};
    mx_sort_arr_int(array, 7);
    for (int i = 0; i <= 6; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    int arr[] = {200, 25, 0, -200, 200, 0, 25};
    mx_sort_arr_int(arr, 7);
    for (int i = 0; i <= 6; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");


    return 0;
}

