//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c ./src/mx*.c
//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c -I inc ./src/mx*.c
//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c libmx.a -lmx
// сайт для сравнения аутпута: https://www.diffchecker.com/text-compare/


#include "inc/libmx.h"
#include <math.h>
#include <limits.h>


void test_mx_printchar(void) {
    printf("\nmx_printchar:\n");
    mx_printchar('A');
    mx_printchar('a');
    mx_printchar('!');
    mx_printchar(' ');
    mx_printchar('9');
    mx_printchar('\'');
    printf("\n__________________________________\n");
}

void test_mx_print_unicode(void) {
    printf("\nmx_print_unicode:\n");
    mx_print_unicode(666);
    mx_print_unicode(1999);
    mx_print_unicode(L'Ω');
    mx_print_unicode(L'☺');
    printf("\n__________________________________\n");
}

void test_mx_printstr(void) {
    printf("\nmx_printstr:\n");
    mx_printstr("Hello, World!\n");
    mx_printstr("This is a test\t\'test1234.");
    printf("\n__________________________________\n");
}

void test_mx_print_strarr(void) {
    printf("\nmx_print_strarr:\n");
    char *arr1[] = {"apple", "banana", "cherry", NULL};
    mx_print_strarr(arr1, " |test\'\t0| \0|\t");
    mx_printchar('\n');
    char *arr2[] = {"one", "two", "three", "four", "five", NULL};
    mx_print_strarr(arr2, "\n!");
    mx_printchar('\n');
    char *arr2_1[] = {"one\f", "test\0TEST", "\'\\\"123\b", "TEST!!\n", NULL};
    mx_print_strarr(arr2_1, " | ");
    mx_printchar('\n');
    char *arr3[] = {"CASE", NULL};
    mx_print_strarr(arr3, "TEST");
    mx_printchar('\n');
    char *arr4[] = {NULL};
    mx_print_strarr(arr4, "TEST");
    printf("\n__________________________________\n");
}

void test_mx_printint(void) {
    printf("\nmx_printint:\n");
    printf("ULLONG_MAX=%llu", ULLONG_MAX); //ULONG_LONG_MAX);
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
    unsigned long long int n6 = 987654321;
    mx_printint(n6); // returns 987654321
    write(1, "\n", 1);
    unsigned long long n7 = -9223372036854775807;
    mx_printint(n7); // returns 1
    write(1, "\n", 1);
    unsigned long long n8 = +9223372036854775807;
    mx_printint(n8); // returns -1
    write(1, "\n", 1);
//    system("leaks -q a.out");
    printf("\n__________________________________\n");
}

void test_mx_pow(void) {
    printf("\nmx_pow:\n");
    double num = 2.5;
    unsigned int power = 3;
    printf("%f\t%f\n", mx_pow(num, power), pow(num, power)); //returns 27
    printf("%f\t%f\n", mx_pow(3, 3), pow(3, 3)); //returns 27
    printf("%f\t%f\n", mx_pow(2.5, 3), pow(2.5, 3)); //returns 15.625
    printf("%f\t%f\n", mx_pow(2, 0), pow(2, 0)); //returns 1
    printf("%f\t%f\n", mx_pow(-3, 3), pow(-3, 3)); //returns -27
    printf("%f\t%f\n", mx_pow(8, 0), pow(8, 0)); //returns 1
    printf("%f\t%f\n", mx_pow(0, 5), pow(0, 5)); //returns 0
    printf("\n__________________________________\n");
}

void test_mx_sqrt(void) {
    printf("\nmx_sqrt:\n");
    printf("%d\t%f\n", mx_sqrt(-1487567761), sqrt(-1487567761)); // 0
    printf("%d\t%f\n", mx_sqrt(0), sqrt(0)); // 0
    printf("%d\t%f\n", mx_sqrt(1), sqrt(1)); // 1
    printf("%d\t%f\n", mx_sqrt(17), sqrt(17)); // 0
    printf("%d\t%f\n", mx_sqrt(1487567761), sqrt(1487567761)); // 38569
    int num = 16;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 4
    num = 4;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 2
    num = -10;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 0
    num = 38;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 0
    num = 0;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 0
    num = 1;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 1
    num = 100;
    printf("%d\t%d\t%f\n", num, mx_sqrt(num), sqrt(num)); //returns 10
    printf("\n__________________________________\n");
}

void test_mx_nbr_to_hex(void) {
    //https://www.rapidtables.com/convert/number/decimal-to-hex.html
    printf("\nmx_nbr_to_hex:\n");
    unsigned long long rep = 18446744073709551615U;
    printf("%llu\n", rep);

    printf("255 = %s\n", mx_nbr_to_hex(255)); // FF
    printf("1024 = %s\n", mx_nbr_to_hex(1024)); // 400
    printf("0 = %s\n", mx_nbr_to_hex(0)); // 0
    printf("%d = %s\n", INT_MIN, mx_nbr_to_hex(INT_MIN)); // 0
    printf("%d = %s\n", __INT_MAX__, mx_nbr_to_hex(__INT_MAX__)); // 7fffffff
    printf("-1 = %s\n", mx_nbr_to_hex(-1)); // 0
    printf("+-678 = %s\n", mx_nbr_to_hex(+-678)); //  0
    printf("-+678 = %s\n", mx_nbr_to_hex(-+678)); //  0
    printf("1234567 = %s\n", mx_nbr_to_hex(1234567)); //  12D687
    printf("-9223372036854775807 = %s\n", mx_nbr_to_hex(-9223372036854775807)); // 8000000000000001
    unsigned long long test = 9223372036854775810U;
    printf("9223372036854775810U = %s\n", mx_nbr_to_hex(test)); //  8000000000000002
    printf("18446744073709551615U = %s\n", mx_nbr_to_hex(18446744073709551615U)); //  ffffffffffffffff
    printf("-18446744073709551615U = %s\n", mx_nbr_to_hex(-18446744073709551615U)); //  1
    printf("9223372036854775807 = %s\n", mx_nbr_to_hex(9223372036854775807)); //  7fffffffffffffff
    printf("775807 = %s\n", mx_nbr_to_hex(775807)); //  bd67f
    printf("176 = %s\n", mx_nbr_to_hex(176)); //  b0
    printf("842 = %s\n", mx_nbr_to_hex(842)); //  34a
    printf("158 = %s\n", mx_nbr_to_hex(158)); //  9e
    printf("471 = %s\n", mx_nbr_to_hex(471)); //  1d7
    printf("1000 = %s\n", mx_nbr_to_hex(1000)); //  3e8
    printf("140732918889176 = %s\n", mx_nbr_to_hex(140732918889176)); //  7ffeefa37ad8
    printf("9223372036854775807 = %s\n", mx_nbr_to_hex(9223372036854775807)); //  7fffffffffffffff
    printf("27 = %s\n", mx_nbr_to_hex(27)); //  1b
    printf("44 = %s\n", mx_nbr_to_hex(44)); //  2c
    printf("\n__________________________________\n");
}

void test_mx_hex_to_nbr(void) {
    printf("\nmx_hex_to_nbr:\n");
    printf("Hex FF to decimal: \t\t%lu\n", mx_hex_to_nbr("FF")); // 255
    printf("Hex 2A to decimal: \t\t%lu\n", mx_hex_to_nbr("2A")); // 42
    printf("Hex 0 to decimal: \t\t%lu\n", mx_hex_to_nbr("0")); // 0
    printf("Hex %s to decimal:%lu\n", "ffffffff80000000", mx_hex_to_nbr("ffffffff80000000")); //18446744071562067968
    printf("Hex %s to decimal:%lu\n", "ffffffffffffffff", mx_hex_to_nbr("ffffffffffffffff")); //18446744073709551615
    printf("Hex %s to decimal: \t%lu\n", "7fffffff", mx_hex_to_nbr("7fffffff")); // 2147483647
    printf("hex=\"%s\"\t\t\tdec=%lu\n", "C4", mx_hex_to_nbr("C4")); //196
    printf("hex=\"%s\"\t\t\tdec=%lu\n", "FADE", mx_hex_to_nbr("FADE")); //6422
    printf("hex=\"%s\"\t\tdec=%lu\n", "ffffffffffff", mx_hex_to_nbr("ffffffffffff")); // 281474976710655
    printf("hex=\"%s\"\t\tdec=%lu\n", "\'!@-FA_de!", mx_hex_to_nbr("\'!@-FA_de!")); // 0
    printf("hex=\"%s\"\t\tdec=%lu\n", "--- -+-59 ", mx_hex_to_nbr("--- -+-59 ")); // 0
    printf("hex=\"%s\"\t\t\tdec=%lu\n", "-A", mx_hex_to_nbr("-A")); // 0
    printf("hex=\"%s\"\t\tdec=%lu\n", "8000000000000002", mx_hex_to_nbr("8000000000000002")); // 9223372036854775810
    printf("hex=\"%s\"\t\tdec=%lu\n", "1000000000000000A", mx_hex_to_nbr("1000000000000000A")); // 10
    // 18446744073709551626 > 18446744073709551615 (unsigned long max 8-byte) by 11
    printf("\n__________________________________\n");
}

void test_mx_itoa(void) {
    printf("\nmx_itoa:\n");
    printf("Int = 12345\t\t string = \"%s\"\n", mx_itoa(12345)); // 12345
    printf("Int = 0\t\t\t string = \"%s\"\n", mx_itoa(0)); // 0
    printf("Int = -9876\t\t string = \"%s\"\n", mx_itoa(-9876)); // -9876
    printf("Int = 1000000\t\t string = \"%s\"\n", mx_itoa(1000000)); // 1000000
    printf("Int = -2147483648\t string = \"%s\"\n", mx_itoa(-2147483648)); // -2147483648
    printf("Int = -2147483647\t string = \"%s\"\n", mx_itoa(-2147483647)); // -2147483647
    printf("Int = 2147483647\t string = \"%s\"\n", mx_itoa(2147483647)); // 2147483647
    printf("Int = -1\t\t string = \"%s\"\n", mx_itoa(-1)); // -1
    printf("Int = 1\t\t\t string = \"%s\"\n", mx_itoa(1)); // 1
    printf("Int = -999999\t\t string = \"%s\"\n", mx_itoa(-999999)); // -999999
    printf("Int = 987654321\t\t string = \"%s\"\n", mx_itoa(987654321)); // 987654321
    printf("\n__________________________________\n");
}

void test_mx_foreach(void) {
    printf("\nmx_for_each:\n");
    int arr[] = {1, 2, 3, 4, 5};
    mx_foreach(arr, 5, mx_printint); // 12345
    printf("\n");
    int arr1[] = {234, 9876, -176547, -2147483648, -2147483647, 2147483647};
    mx_foreach(arr1, 6, mx_printint); // 2349876-176547-2147483648-21474836472147483647
    printf("\n");
//    system("leaks -q res");
    printf("\n__________________________________\n");
}

void test_mx_binary_search(void) {
    printf("\nmx_binary_search:\n");
    char *arr[] = {"apple", "banana", "cherry", "date", "fig", "grape", "kiwi"};
    int size = 7, count1 = 0, result1 = mx_binary_search(arr, size, "date", &count1);
    printf("Index of 'date' in the sorted array: %d (Count: %d)\n", result1, count1);

    int count2 = 0, result2 = mx_binary_search(arr, size, "kiwi", &count2);
    printf("Index of 'kiwi' in the sorted array: %d (Count: %d)\n", result2, count2);

    int count3 = 0, result3 = mx_binary_search(arr, size, "banana", &count3);
    printf("Index of 'banana' in the sorted array: %d (Count: %d)\n\n", result3, count3);

    char* arr2[6] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int size_ = 6, count = 0;
    const char *s = "z";
    for (int i = 0; i < size_; i++)
        printf("\"%s\"\t", arr2[i]);
    printf("\nsearch_string = \"%s\"\n", s);
    printf("mx_binary_search = %d\ncount = %d\n\n", mx_binary_search(arr2, size_, s, &count), count); // 5 3

    s = "Test";
    for (int i = 0; i < size_; i++)
        printf("\"%s\"\t", arr2[i]);
    printf("\nsearch_string = \"%s\"\n", s);
    printf("mx_binary_search = %d\ncount = %d\n", mx_binary_search(arr2, size_, s, &count), count); // -1 0
    printf("\n__________________________________\n");
}

void test_mx_bubble_sort(void) {
    printf("\nmx_bubble_sort:\n");
    char *arr[] = {"grape", "banana", "kiwi", "apple", "date", "cherry", "fig"};
    int size = 7;
    printf("Initial array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    int swaps1 = mx_bubble_sort(arr, size); // 11
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("(Swaps: %d)\n", swaps1);

    char *arr2[] = {"z", "x", "a", "b", "c"};
    int size2 = 5;
    printf("Initial array: ");
    for (int i = 0; i < size2; i++) {
        printf("%s ", arr2[i]);
    }
    printf("\n");

    int swaps2 = mx_bubble_sort(arr2, size2); // 7
    printf("Sorted array: ");
    for (int i = 0; i < size2; i++) {
        printf("%s ", arr2[i]);
    }
    printf("(Swaps: %d)\n\n", swaps2);

    char *arr1[] = {"abc", "acb", "a"};
    for (int i = 0; i < 3; i++)
        printf("%s\t", arr1[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr1, 3)); // counter=2
    for (int i = 0; i < 3; i++)
        printf("%s\t", arr1[i]);
    printf("\n\n");

    char *arr2_[] = {"abc", "xyz", "ghi", "def"};
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr2_[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr2_, 4)); // counter=3
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr2_[i]);
    printf("\n\n");

    char *arr3[] = {"456", "412", "987", "123"};
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr3[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr3, 4)); // counter=4
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr3[i]);
    printf("\n\n");

    char *arr4[] = {"12", "34", "56", "78"};
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr4[i]);
    printf("\ncounter=%d\n", mx_bubble_sort(arr4, 4)); // counter=0
    for (int i = 0; i < 4; i++)
        printf("%s\t", arr4[i]);
    printf("\n");

    char *array[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count = 0;
    printf("\nswaps = %d\tcount = %d\n", mx_binary_search(array, 6, "ab", &count), count); //swaps=3 and count=3
    count = 0;
    printf("swaps = %d\tcount = %d\n", mx_binary_search(array, 6, "aBc", &count), count); //swaps=2 and count=1
    count = 0;
    printf("swaps = %d\tcount = %d\n", mx_binary_search(array, 6, "aBz", &count), count); //swaps=-1 and count=0
    printf("\n__________________________________\n");
}

void test_mx_quicksort(void) {
    printf("\nmx_quicksort:\n");
    printf("\nmx_quicksort:\n");
    char *arr[] = {"grape", "banana", "kiwi", "apple", "date", "cherry", "fig"};
    int size = 7, swaps1 = mx_quicksort(arr, 0, size - 1);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("(Swaps: %d)\n", swaps1); // 3

    char *arr2[] = {"z", "x", "a", "b", "c"};
    int size2 = 5, swaps2 = mx_quicksort(arr2, 0, size2 - 1);
    printf("Sorted array: ");
    for (int i = 0; i < size2; i++) {
        printf("%s ", arr2[i]);
    }
    printf("(Swaps: %d)\n", swaps2); // 0

    char *arr_1[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    int counter_1 = mx_quicksort(arr_1, 0, 3);
    printf("\ncounter = %d\nSorted array:\t", counter_1); // 2
    for (int i = 0; i < 4; ++i) {
        printf("%s\t", arr_1[i]);
    }
    printf("\n");

    char *arr_2[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};
    int counter_2 = mx_quicksort(arr_2, 0, 5);
    printf("\ncounter = %d\nSorted array:\t", counter_2); // 2
    for (int i = 0; i < 6; ++i) {
        printf("%s\t", arr_2[i]);
    }
    printf("\n");

    char *arr_3[] = {"TEST9", "test1", "aBcD", "AbCd", "aBCDEFG", "aBc", "Abcdefg"};
    int counter_3 = mx_quicksort(arr_3, 0, 6);
    printf("\ncounter = %d\nSorted array:\t", counter_3); // 3
    for (int i = 0; i < 7; ++i) {
        printf("%s\t", arr_3[i]);
    }
    printf("\n");

    char *arr_4[] = {"1234", "9", "4321", "1", "678", "12345", "123", "12", "456", "11"};
    int counter_4 = mx_quicksort(arr_4, 0, 9);
    printf("\ncounter = %d\nSorted array:\t", counter_4); // 8
    for (int i = 0; i < 10; ++i) {
        printf("%s\t", arr_4[i]);
    }
    printf("\n");
    printf("\n__________________________________\n");
}

void test_mx_strlen(void) {
    printf("\nmx_strlen:\n");
    const char *str1 = "Hello, World!";
    printf("MX_Length of '%s' is %d\n", str1, mx_strlen(str1)); // 13
    printf("STANDART_Length of '%s' is %lu\n", str1, strlen(str1)); // 13

    const char *str2 = "";
    printf("MX_Length of '%s' is %d\n", str2, mx_strlen(str2)); // 0
    printf("STANDART_Length of '%s' is %lu\n", str2, strlen(str2)); // 0

    const char *str3 = "|test\'\t0| \f\b \0|\t|";
    printf("MX_Length of the string \"%s\" is %d.\n", str3, mx_strlen(str3)); // 13
    printf("STANDART_Length of the string \"%s\" is %lu.\n", str3, strlen(str3)); // 13
    printf("\n__________________________________\n");
}

void test_mx_swap_char(void) {
    printf("\nmx_swap_char:\n");
    char str1[] = "abcd";
    mx_swap_char(&str1[1], &str1[2]);
    printf("After swapping(1&2): %s\n", str1); //acbd

    char str[] = "ONE";
    printf("Initial:\t%s\n", str); // NEO
    mx_swap_char(&str[0], &str[1]);
    printf("0&1\t\t%s\n", str); // NOE
    mx_swap_char(&str[1], &str[2]);
    printf("1&2:\t\t%s\n", str); // NEO
    printf("\n__________________________________\n");
}

void test_mx_str_reverse(void) {
    printf("\nmx_str_reverse:\n");
    char str1[] = "abcdef";
    printf("%s\t\t->\t", str1);
    mx_str_reverse(str1);
    printf("%s\n", str1);

    char str2[] = "12345";
    printf("%s\t\t->\t", str2);
    mx_str_reverse(str2);
    printf("%s\n", str2);

    char str3[] = "game over";
    printf("%s\t->\t", str3);
    mx_str_reverse(str3);
    printf("%s\n", str3);

    char str4[] = "|test\'\t0| \b\f \0|\t|";
    printf("%s\t->\t", str4);
    mx_str_reverse(str4);
    printf("%s\n", str4);
    printf("\n__________________________________\n");
}

void test_mx_strdel(void) {
    printf("\nmx_strdel:\n");
//    char *str1 = mx_strdup("Hello, World!");
//    mx_strdel(&str1);
//    printf("str1 = %s\n", str1);

    char *s1 = malloc(5 * sizeof(*s1));
    if (s1 != NULL) {
        for (int i = 0; i < 5; i++) {
            s1[i] = '0';
        }
        printf("s1 = %s\n", s1); // 00000
    }
    char **s2 = &s1;
    mx_strdel(s2);
    printf("s2 = %s\n", *s2); // (null)
    printf("\n__________________________________\n");
}

void test_mx_del_strarr(void) {
    printf("\nmx_del_strarr:\n");
    int count = 5;
    char **arr = malloc(sizeof(char*) * (count + 1));
    for (int i = 0; i < count; ++i) {
        arr[i] = (char *) malloc(sizeof(char) * 10);
    }
    arr[count] = NULL;
    printf("arr = \t");
    for (int i = 0; i <= count; ++i) {
        printf("\'%s\'\t", arr[i]);
    }
    mx_del_strarr(&arr);
    printf("\ndel_strarr:\t\'%p\'\n", (void*)arr); // виводить адресу в шістнадцятковому форматі NULL = 0x0
    printf("\n__________________________________\n");
}

void test_mx_get_char_index(void) {
    printf("\nmx_get_char_index:\n");
    const char *str1 = "Hello, World!";
    printf("Index of 'o' in '%s':%d\n", str1, mx_get_char_index(str1, '0'));
    const char *str2 = "abcde";
    printf("Index of 'z' in '%s':\t%d\n", str2, mx_get_char_index(str2, 'z'));
    const char *str3 = NULL;
    printf("Index of '!' in '%s':\t%d\n", str3, mx_get_char_index(str3, '!'));
    printf("\n__________________________________\n");

}

void test_mx_strdup(void) {
    printf("\nmx_strdup:\n");
    const char *str1 = "Hello, World!";
    char *copy1 = mx_strdup(str1);
    printf("Copied string: \'%s\'\n", copy1);
    const char *str2 = "";
    char *copy2 = mx_strdup(str2);
    printf("Copied string (empty): \'%s\'\n", copy2);
    const char *str3 = "What's up, Neo?";
    printf("mx_strdup:\tstr=\"%s\"\tdst=\"%s\"\n", str3, mx_strdup(str3));
    printf("strdup:\t\tstr=\"%s\"\tdst=\"%s\"\n\n", str3, strdup(str3));
    const char *str4 = "test\'!\"@#92%^&*\b;\f!\r!!";
    printf("mx_strdup:\tstr=\"%s\"\tdst=\"%s\"\n", str4, mx_strdup(str4));
    printf("strdup:\t\tstr=\"%s\"\tdst=\"%s\"\n", str4, strdup(str4));
    printf("\n__________________________________\n");
}

void test_mx_strndup(void) {
    printf("\nmx_strndup:\n");
    const char *str1 = "Hello, World!";
    printf("Copied string (5 chars): mx = \'%s\'\tst = \'%s\'\n", mx_strndup(str1, 5), strndup(str1, 5)); // 'Hello'
    const char *str2 = "abcdef";
    printf("Copied string (3 chars): mx = \'%s\'\tst = \'%s\'\n", mx_strndup(str2, 3), strndup(str2, 3)); // 'abc'

    const char *str3 = "AbCdEfG";
    char *dup1_1 = mx_strndup(str3, 4);
    int len1_1 = mx_strlen(dup1_1);
    char *dup1_2 = strndup(str3, 4);
    int len1_2 = strlen(dup1_2);
    printf("\n3.MX_len1_1 = %d\tstr = \'%s\'\n"
           "ST_len1_2 = %d\tstr = \'%s\'\n\n",
           len1_1, dup1_1, len1_2, dup1_2); // len = 4, 'AbCd'

    const char *str4 = "What's up, Neo?";
    printf("mx:\tstr=\"%s\"\tdst=\"%s\"\tlen=%d\n", str4, mx_strndup(str4, 9), mx_strlen(mx_strndup(str4, 9))); // len = 9, 'What's up'
    printf("st:\tstr=\"%s\"\tdst=\"%s\"\tlen=%lu\n\n", str4, strndup(str4, 9), strlen(strndup(str4, 9))); // len = 9

    const char *str5 = "test\'!\"@#92%^&*\b;\f!\r!!";
    printf("mx:\tstr=\"%s\"\tdst=\"%s\"\tlen=%d\n", str5, mx_strndup(str5, 25), mx_strlen(mx_strndup(str5, 25))); // len = 22, 'test'!"@#92%^&;
    //!!'
    printf("st:\tstr=\"%s\"\tdst=\"%s\"\tlen=%lu\n\n", str5, strndup(str5, 25), strlen(mx_strndup(str5, 25))); // len = 22
    printf("\n__________________________________\n");
}

void test_mx_strcpy(void) {
    printf("\nmx_strcpy:\n");
    char dest1_1[5];
    const char *src1_1 = "Hello, World!";
    mx_strcpy(dest1_1, src1_1);
    printf("0.1Copied string (dst=5 chars): %s\n", dest1_1);

    char dest2_1[10];
    const char *src2_1 = "abc";
    mx_strcpy(dest2_1, src2_1);
    printf("0.2Copied string (dst=10 chars): %s\n", dest2_1);

    char dest1[9];
    char dest11[9];
    const char *src1 = "TESTtest";
    printf("1.1 Copied string (dst=8 chars): \'%s\'\tlen=%d\n",
           mx_strcpy(dest1, src1),
           mx_strlen(strcpy(dest1, src1)));
    printf("1.2 Copied string (dst=8 chars): \'%s\'\tlen=%lu\n",
           strcpy(dest11, src1),
           strlen(strcpy(dest11, src1)));

    char *dest2 = mx_strnew(5);
    char *dest22 = mx_strnew(5);
    strcpy(dest2, "Hello");
    strcpy(dest22, "Hello");
    const char *src2 = "abc";
    printf("2.1 Copied string (dst=5 chars): \'%s\'\tlen=%d\n",
           mx_strcpy(dest2, src2),
           mx_strlen(strcpy(dest2, src2)));
    printf("2.2 Copied string (dst=5 chars): \'%s\'\tlen=%lu\n",
           strcpy(dest22, src2),
           strlen(strcpy(dest22, src2)));

//    char dest4[6]; //Segmentation fault
//    char dest44[6]; //Segmentation fault:
    char *dest4 = mx_strnew(0);
    char *dest44 = mx_strnew(0);
    const char *src4 = "ABCD";
    printf("3.1 Copied string (dst=0 chars): \'%s\'\tlen=%d\n",
           mx_strcpy(dest4, src4),
           mx_strlen(strcpy(dest4, src4)));
    printf("3.2 Copied string (dst=0 chars): \'%s\'\tlen=%lu\n",
           strcpy(dest44, src4),
           strlen(strcpy(dest44, src4)));
    printf("\n__________________________________\n");
}

void test_mx_strncpy(void) {
    printf("\nmx_strncpy:\n");
    char dest1[6];
    const char *src1 = "Hello, World!";
    printf("1.1Copied string (5 chars): \'%s\'\n", mx_strncpy(dest1, src1, 5)); // len 8
    printf("1.2Copied string (5 chars): \'%s\'\n", strncpy(dest1, src1, 5));

    char *dest2 = mx_strnew(5);
    strcpy(dest2, "Hello");
    const char *src2 = "abc";
    printf("2.1Copied string (5 chars): \'%s\'\n", mx_strncpy(dest2, src2, 5)); // len 3
    printf("2.2Copied string (5 chars): \'%s\'\n", strncpy(dest2, src2, 5));

    char dest4[6];
    const char *src4 = "abc";
    printf("3.1Copied string (0 chars): \'%s\'\n", mx_strncpy(dest4, src4, 0)); // len 4
    printf("3.2Copied string (0 chars): \'%s\'\n", strncpy(dest4, src4, 0));
    printf("\n__________________________________\n");
}

void test_mx_strcmp(void) {
    printf("\nmx_strcmp:\n");
    const char *str1 = "apple";
    const char *str2 = "banana";
    int result1 = mx_strcmp(str1, str2);
    printf("Comparison result: %d\n", result1); // -1

    const char *str3 = "cherry";
    const char *str4 = "cherry";
    int result2 = mx_strcmp(str3, str4);
    printf("Comparison result: %d\n", result2); // 0

    const char *str5 = "apple";
    const char *str6 = "Apples";
    int result3 = mx_strcmp(str5, str6);
    printf("Comparison result: %d\n\n", result3); //32

    const char *str11 = "Hello";
    const char *str22 = "hello";
    const char *str33 = "World";

    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n", str11, str22, mx_strcmp(str11, str22), strcmp(str11, str22)); //-32
    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n\n", str11, str33, mx_strcmp(str11, str33), strcmp(str11, str33)); //15

    str11 = "english";
    str22 = "eng";
    str33 = "World";

    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n", str11, str22, mx_strcmp(str11, str22), strcmp(str11, str22)); //108
    printf("Compare '%s' and '%s': mx_strcmp=%d and strcmp=%d\n\n", str11, str33, mx_strcmp(str11, str33), strcmp(str11, str33)); //14
    printf("\n__________________________________\n");
}

void test_mx_strcat(void) {
    printf("\nmx_strcat:\n");
    char dest1_1[20] = "Hello, ";
    char dest1_2[20] = "Hello, ";
    const char *src1 = "World!";
    mx_strcat(dest1_1, src1);
    strcat(dest1_2, src1);
    printf("1_MX_Concatenated string(len1): \'%s\'\tlen=%d\n", dest1_1, mx_strlen(dest1_1)); // len=13
    printf("1_ST_Concatenated string(len1): \'%s\'\tlen=%lu\n", dest1_2, strlen(dest1_2));

    char *dest2_1 = mx_strnew(1);
    char *dest2_2 = mx_strnew(1);
    mx_strcpy(dest2_1, "abc");
    strcpy(dest2_2,"abc");
//    char dest2_1[7] = "ABC";
//    char dest2_2[7] = "ABC";
    const char *src2 = "def";
    mx_strcat(dest2_1, src2);
    strcat(dest2_2, src2);
    printf("2_MX_Concatenated string(len1): \'%s\'\tlen=%d\n", dest2_1, mx_strlen(dest2_1)); // len=6
    printf("2_ST_Concatenated string(len1): \'%s\'\tlen=%lu\n", dest2_2, strlen(dest2_2));

    char *dest3_1 = mx_strnew(15);
    char *dest3_2 = mx_strnew(15);
    mx_strcpy(dest3_1, "test");
    strcpy(dest3_2,"test");
    const char *src3 = "\tTEST";
    mx_strcat(dest3_1, src3);
    strcat(dest3_2, src3);
    printf("3_MX_Concatenated string(len15): \'%s\'\tlen=%d\n", dest3_1, mx_strlen(dest3_1)); // len=9
    printf("3_ST_Concatenated string(len15): \'%s\'\tlen=%lu\n", dest3_2, strlen(dest3_2));

//    char *dest4_1 = mx_strnew(10);
//    char *dest4_2 = mx_strnew(10);
//    mx_strcpy(dest4_1, NULL);
//    strcpy(dest4_2,NULL);
//    const char *src4 = "empty";
    char dest4_1[20] = "";
    char dest4_2[20] = "";
    const char *src4 = "TestQueen\0 1234";
    mx_strcat(dest4_1, src4);
    strcat(dest4_2, src4);
    printf("4_MX_Concatenated string(len15): \'%s\'\tlen=%d\n", dest4_1, mx_strlen(dest4_1)); // len=9
    printf("4_ST_Concatenated string(len15): \'%s\'\tlen=%lu\n", dest4_2, strlen(dest4_2));
    printf("\n__________________________________\n");
}

void test_mx_strncmp(void){
    printf("\nmx_strncmp:\n");
    const char *str1 = "Hey, Neo!";
    const char *str2 = "Hey,Neo!";
    printf("1_MX_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str1, str2, mx_strncmp(str1, str2, 9)); //-46
    printf("1_ST_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str1, str2, strncmp(str1, str2, 9)); //-46
    const char *str3 = "Hey, Neo!";
    const char *str4 = "Hey, Neo !";
    printf("2_MX_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str3, str4, mx_strncmp(str3, str4, 4)); //0
    printf("2_ST_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str3, str4, strncmp(str3, str4, 4)); //0
    const char *str5 = "hello";
    const char *str6 = "Hello2";
    printf("3_MX_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str5, str6, mx_strncmp(str5, str6, 8)); //32
    printf("3_ST_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str5, str6, strncmp(str5, str6, 8)); //32
    str5 = "string";
    str6 = "str";
    printf("3_MX_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str5, str6, mx_strncmp(str5, str6, 8)); // 105
    printf("3_ST_str1=\'%s\',\tstr2=\'%s\'\tcmp=%d\n", str5, str6, strncmp(str5, str6, 8)); // 105
    const char *string1 = "Hey, Neo!";
    const char *string2 = "Hey,Neo!";
    printf("4. strncmp=%d\n", strncmp(string1, string2, 9)); //-46
    printf("4. mx_strncmp=%d\n", mx_strncmp(string1, string2, 9)); //-46
    printf("\n__________________________________\n");
}

void test_mx_strchr(void) {
    printf("\nmx_strchr:\n");
    const char *str1 = "Hello, world!";
    char target1 = 'l';
    printf("Результат 1: mx_strchr=\'%s\'\t", mx_strchr(str1, target1)); // "llo, world!"
    printf("strchr=%s\n", strchr(str1, target1)); // "llo, world!"
    const char *str2 = "Programming";
    int target2 = 97; // 'a'
    printf("Результат 2: mx_strchr=\'%s\'\t\t", mx_strchr(str2, target2)); // 'amming'
    printf("strchr=\'%s\'\n", strchr(str2, target2)); // 'amming'
    char *str3 = mx_strnew(14);
    mx_strcpy(str3, "Program1ming!!");
    char target3 = '1';
    printf("Результат 3: mx_strchr=\'%s\'\t", mx_strchr((const char *)str3, target3)); // "1ming!!"
    printf("strchr=\'%s\'\n", strchr((const char *)str3, target3)); // "1ming!!"
    char s1[] = "0123 t456789";
    printf("result 4: strchr=\'%s\'\t", strchr(s1, ' ')); //t456789
    printf("mx_strchr=\'%s\'\n", mx_strchr(s1, ' ')); //t456789
    char s2[] = "AbcDEf\n98765678";
    printf("result 5: strchr=\'%s\'\t", strchr(s2, 10)); //\n98765678
    printf("mx_strchr=\'%s\'\n", mx_strchr(s2, 10)); //\n98765678
    char s3[] = "AbcDEf\n98765678";
    printf("result 6: strchr=\'%s\'\t", strchr(s3, 'Z')); //'(null)'
    printf("mx_strchr=\'%s\'\n", mx_strchr(s3, 'Z')); //'(null)'
    printf("\n__________________________________\n");
}

void test_mx_strstr(void) {
    printf("\nmx_strstr:\n");
    const char *haystack1 = "Hello, World!";
    const char *needle1 = "World";
    char *result1 = mx_strstr(haystack1, needle1);
    printf("1. Substring found: \'%s\'\n", result1); //'World!'
    const char *haystack2 = "The quick brown fox";
    const char *needle2 = "lazy dog";
    char *result2 = mx_strstr(haystack2, needle2);
    printf("2. Substring found: \'%s\'\n", result2); // '(null)'
    const char *str1 = "-0123456789 .";
    const char *str2 = "456";
    printf("3. strstr=\'%s\'\tmx_strstr=\'%s\'\n", strstr(str1, str2), mx_strstr(str1, str2));// '456789 .'
    const char *str3 = "TEstkGsjjsdhGFDSGHJFD\t9876589";
    const char *str4 = "G";
    printf("4. strstr=\'%s\'\tmx_strstr=\'%s\'\n", strstr(str3, str4), mx_strstr(str3, str4));// 'GsjjsdhGFDSGHJFD     9876589'
    const char *str5 = "";
    printf("5. strstr=\'%s\'\tmx_strstr=\'%s\'\n", strstr(str3, str5), mx_strstr(str3, str5));// 'TEstksjjsdhGFDSGHJFD	9876589'
    const char *str6 = "ZaZ";
    printf("6. strstr=\'%s\'\tmx_strstr=\'%s\'\n", strstr(str3, str6), mx_strstr(str3, str6));// '(null)'
    printf("\n__________________________________\n");
}

void test_mx_get_substr_index(void) {
    printf("\nmx_get_substr_index:\n");
    const char *str1 = "Hello, World!";
    const char *sub1 = "World";
    printf("Index of '%s' in '%s': %d\n", sub1, str1, mx_get_substr_index(str1, sub1)); // 7
    const char *str2 = "The quick brown fox";
    const char *sub2 = "lazy dog";
    printf("Index of '%s' in '%s': %d\n", sub2, str2, mx_get_substr_index(str2, sub2)); // -1
    const char *str3 = "McDonalds";
    const char *sub3 = "Don";
    printf("Index of '%s' in '%s': %d\n", sub3, str3, mx_get_substr_index(str3, sub3)); // 2
    const char *sub4 = "on";
    printf("Index of '%s' in '%s': %d\n", sub4, str3, mx_get_substr_index(str3, sub4)); // 3
    const char *sub5 = "Donatello";
    printf("Index of '%s' in '%s': %d\n", sub5, str3, mx_get_substr_index(str3, sub5)); // -1
    const char *sub6 = NULL;
    printf("Index of '%s' in '%s': %d\n", sub6, str3, mx_get_substr_index(str3, sub6)); // -2
    const char *sub7 = "";
    printf("Index of '%s' in '%s': %d\n", sub7, str3, mx_get_substr_index(str3, sub7)); // 0
    printf("\n__________________________________\n");
}

void test_mx_count_substr(void) {
    printf("\nmx_count_substr:\n");
    const char *str1 = "Hello, World! Hello, Universe!";
    const char *sub1 = "Hello";
    int count1 = mx_count_substr(str1, sub1);
    printf("Occurrences of '%s' in '%s': %d\n", sub1, str1, count1);
    const char *str2 = "The quick brown fox jumps over the lazy dog."; // 2
    const char *sub2 = "the";
    int count2 = mx_count_substr(str2, sub2);
    printf("Occurrences of '%s' in '%s': %d\n", sub2, str2, count2); // 1
    const char *string = "yo, yo, yo Neo";
    const char *substring = "yo";
    printf("Occurrences of '%s' in '%s': %d\n", substring, string, mx_count_substr(string, substring)); // 3
    const char *substring1 = "";
    printf("Occurrences of '%s' in '%s': %d\n", substring1, string, mx_count_substr(string, substring1)); // 0
    const char *string2 = NULL;
    const char *substring2 = "test";
    printf("Occurrences of '%s' in '%s': %d\n", substring2, string2, mx_count_substr(string2, substring2)); // -1
    const char *substring3 = NULL;
    printf("Occurrences of '%s' in '%s': %d\n", substring3, string, mx_count_substr(string, substring3)); // -1
    printf("Occurrences of '%s' in '%s': %d\n", substring3, string2, mx_count_substr(string2, substring3)); // -1
    const char *string4 = "";
    const char *substring4 = "";
    printf("Occurrences of '%s' in '%s': %d\n", substring4, string4, mx_count_substr(string4, substring4)); // 0
    printf("\n__________________________________\n");
}

void test_mx_count_words(void) {
    printf("\nmx_count_words:\n");
    const char *str1 = "Hello, World!";
    char delim1 = ' ';
    int words1 = mx_count_words(str1, delim1);
    printf("Word count in '%s' with delim ' ': %d\n", str1, words1); // 2
    const char *str2 = "The quick brown fox";
    int words2 = mx_count_words(str2, delim1);
    printf("Word count in '%s' with delim ' ': %d\n", str2, words2); // 4
    const char *string = "Wake up, Neo! You are the chosen one!";
    printf("Word count in '%s' with delim ' ': %d\n", string, mx_count_words(string, delim1)); // 8
    const char *string1 = "     Wake  up,   Neo! You are the chosen*one   ! \0";
    printf("Word count in '%s' with delim ' ': %d\n", string1, mx_count_words(string1, delim1)); // 8
    const char *string2 = NULL;
    printf("Word count in '%s' with delim ' ': %d\n", string2, mx_count_words(string2, delim1)); // -1
    char delim2 = '*';
    const char *string3 = "  follow  *   the  white rabbit \0";
    printf("Word count in '%s' with delim '*': %d\n", string3, mx_count_words(string3, delim2)); // 2
    printf("Word count in \'%s\' with delim ' ': %d\n", string3, mx_count_words(string3, delim1)); // 5
    const char *string4 = "";
    printf("Word count in '%s' with delim ' ': %d\n", string4, mx_count_words(string4, delim1)); // 0
    string4 = "   ";
    printf("Word count in '%s' with delim ' ': %d\n", string4, mx_count_words(string4, delim1)); // 0
    printf("\n__________________________________\n");
}

void test_mx_strnew(void) {
    printf("\nmx_strnew:\n");
    int size = 10, num = 48;
    char *str1 = mx_strnew(size);
    for (int i = 0; i < size; i++) {
        str1[i] = num;
        num++;
    }
    printf("New string of size %d:\tstr = \'%s\'\tlen = %lu\n", size, str1, strlen(str1)); // str = '0123456789', len = 10
    size = 0, num = 48;
    char *str2 = mx_strnew(size);
    for (int i = 0; i < size; i++) {
        str2[i] = num;
        num++;
    }
    printf("New string of size %d:\tstr = \'%s\'\t\tlen = %lu\n", size, str2, strlen(str2)); // str = '', len = 0
    size = -5, num = 48;
    char *str3 = mx_strnew(size);
    for (int i = 0; i < size; i++) {
        str3[i] = num;
        num++;
    }
    printf("New string of size %d:\t", size);
    if (str3 != NULL) {
        printf("str = \'%s\'\tlen = %lu\n", str3, strlen(str3));
    } else {
        printf("Segmentation fault: STR = NULL\n"); //
    }
    printf("\n__________________________________\n");
}

void test_mx_strtrim(void) {
    printf("\nmx_strtrim:\n");
    const char *str1 = "  Hello, World!  ";
    printf("Trimmed string: '%s'\n", mx_strtrim(str1)); // 'Hello, World!'
    const char *str2 = "    ";
    printf("Trimmed string: '%s'\n", mx_strtrim(str2)); // ''
    const char *str3 = "\t\n\v\r\f   TEST1213456789jhgsdb\\0      kjcbdsjkc546367875644    \t\n\v\r\f    \0";
    printf("Trimmed string: '%s'\n", mx_strtrim(str3)); // 'TEST1213456789jhgsdb\0      kjcbdsjkc546367875644'
    const char *str4 = "";
    printf("Trimmed string: '%s'\n", mx_strtrim(str4)); // ''
    const char *str5 = NULL;
    printf("Trimmed string: '%s'\n", mx_strtrim(str5)); // '(null)'
    const char *str6 = "\f   My name... is Neo \t\n ";
    printf("Trimmed string: '%s'\n", mx_strtrim(str6)); // 'My name... is Neo'
    printf("\n__________________________________\n");
}

void test_mx_del_extra_spaces(void) {
    printf("\nmx_del_extra_spaces:\n");
    const char *str1 = "  Hello, \t \n    World!  \a";
    printf("String with extra spaces removed: \'%s\'\n", mx_del_extra_spaces(str1)); // 'Hello, World! '
    const char *str2 = "    ";
    printf("String with extra spaces removed: \'%s\'\n", mx_del_extra_spaces(str2)); // ''
    const char *string1 = "\f\v\r  My name...   is \r Neo \t\n  ";
    printf("String with extra spaces removed: \'%s\'\n", mx_del_extra_spaces(string1)); // 'My name... is Neo'
    const char *string2 = "";
    printf("String with extra spaces removed: \'%s\'\n", mx_del_extra_spaces(string2)); // ''
    const char *string3 = NULL;
    printf("String with extra spaces removed: \'%s\'\n", mx_del_extra_spaces(string3)); // '(null)'
    printf("\n__________________________________\n");
}

void test_mx_strsplit(void) {
    printf("\nmx_strsplit:\n");
    const char *str1 = "Hello,World";
    char delim1 = ',';
    char **split1 = mx_strsplit(str1, delim1);
    printf("1. Split string \"%s\" (delimiter=\'%c\'):\t", str1, delim1);
    for (int i = 0; split1[i] != NULL; i++) {
        printf("i=%d [%s]\t", i, split1[i]); // i=0 [Hello]     i=1 [World]
        free(split1[i]);
    }
    printf("\n");

    const char *str2 = "The quick brown fox";
    char delim2 = ' ';
    char **split2 = mx_strsplit(str2, delim2);
    printf("2. Split string \"%s\" (delimiter=\'%c\'):\t", str2, delim2);
    for (int i = 0; split2[i] != NULL; i++) {
        printf("i=%d [%s]\t", i, split2[i]); // i=0 [The]       i=1 [quick]     i=2 [brown]     i=3 [fox]
    }
    printf("\n");

    const char *s = "**Good bye,**Mr.*Anderson.****";
    char cher = '*';
    char **arr = mx_strsplit(s, cher);
    printf("3. Split string \"%s\" (delimiter=\'%c\'):\t", s, cher);
    for (int i = 0; i < mx_count_words(s, cher); i++) {
        printf("i=%d [%s]\t", i, arr[i]); // i=0 [Good bye,]     i=1 [Mr.]       i=2 [Anderson.]
    }
    printf("\n");

    const char *s2 = "    Knock, knock,    Neo.    ";
    char cher1 = ' ';
    char **arr2 = mx_strsplit(s2, cher1);
    printf("4. Split string \"%s\" (delimiter=\'%c\'):\t", s2, cher1);
    for (int i = 0; arr2[i]; i++) {
        printf("i=%d [%s]\t", i, arr2[i]); // i=0 [Knock,]    i=1 [knock,]    i=2 [Neo.]
    }
    printf("\n");

    const char *s3 = "    ";
    char **arr3 = mx_strsplit(s3, cher);
    printf("5. Split string \"%s\" (delimiter=\'%c\'):\t", s3, cher);
    for (int i = 0; arr3[i]; i++) {
        printf("i=%d [%s]\t", i, arr3[i]); // i=0 [    ]
    }
    printf("\n");

    char **arr4 = mx_strsplit(s3, cher1);
    printf("6. Split string \"%s\" (delimiter=\'%c\'):\t", s3, cher1);
    printf("[%s]\n", arr4[0]); // [(null)]

    const char *s5 = NULL;
    char **arr5 = mx_strsplit(s5, cher1);
    if (arr5) {
        printf("7. Split string \"%s\" (delimiter=\'%c\'):\t", s5, cher1);
    } else {
        printf("7. Split string \"%s\" (delimiter=\'%c\'):\tArr5 = NULL\n", s5, cher1); // Arr5 = NULL
    }
//    system("leaks -q a.out");
    //Process 40186: 234 nodes malloced for 17 KB
    //Process 40186: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_mx_strjoin(void) {
    printf("\nmx_strjoin:\n");
    const char *s1 = "Hello, ", *s2 = "World!";
    char *jstr1 = mx_strjoin(s1, s2);
    printf("Concatenated string: \'%s\'\n", jstr1 ); // 'Hello, World!'
    const char *s3 = "abc", *s4 = "def";
    char *jstr2 = mx_strjoin(s3, s4);
    printf("Concatenated string: \'%s\'\n", jstr2); // 'abcdef'
    char *str1 = "Neo", *str2 = "Hey, ", *str3 = NULL;
    char *jstr3 = mx_strjoin(str2, str1);
    printf("Concatenated string: \'%s\'\n", jstr3); // 'Hey, Neo'
    char *jstr4 = mx_strjoin(str1, str3);
    printf("Concatenated string: \'%s\'\n", jstr4); // 'Neo'
    char *jstr5 = mx_strjoin(str3, str3);
    printf("Concatenated string: \'%s\'\n", jstr5); // '(null)'
//    system("leaks -q a.out");
//    Process 47832: 219 nodes malloced for 16 KB
//    Process 47832: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_mx_file_to_str(void) {
    printf("\nmx_file_to_str:\n");
    const char *file1 = "sample.txt";
    char *content1 = mx_file_to_str(file1);
    if (content1 != NULL) {
        printf("File content of \'%s\':\n[%s]\n", file1, content1);
        mx_strdel(&content1);
    } else {
        printf("Failed to read file: \'%s\'\n", file1);
    }

    const char *file2 = "nonexistent.txt";
    char *content2 = mx_file_to_str(file2);
    if (content2 != NULL) {
        printf("File content of \'%s\':\n[%s]\n", file2, content2);
        mx_strdel(&content2);
    } else {
        printf("Failed to read file: \'%s\'\n", file2);
    }

    const char *file3 = NULL;
    char *content3 = mx_file_to_str(file3);
    if (content3 != NULL) {
        printf("File content of \'%s\':\n[%s]\n", file3, content3);
        mx_strdel(&content3);
    } else {
        printf("Failed to read file: \'%s\'\n", file3);
    }
    printf("\n__________________________________\n");
}

void test_mx_replace_substr(void) {
    printf("\nmx_replace_substr:\n");
    const char *str1 = "Hello, World! Hello, Universe!";
    const char *sub1 = "Hello";
    const char *replace1 = "Hi";
    char *result1 = mx_replace_substr(str1, sub1, replace1);
    printf("1.1. \'%s\'\t replace \'%s\' with \'%s\'\n1.2. \'%s\'\n", str1, sub1, replace1, result1);
    mx_strdel(&result1);

    const char *str2 = "The quick brown fox jumps over the lazy dog.";
    const char *sub2 = "the";
    const char *replace2 = "a";
    char *result2 = mx_replace_substr(str2, sub2, replace2);
    printf("2.1. \'%s\'\t replace \'%s\' with \'%s\'\n2.2. \'%s\'\n", str2, sub2, replace2, result2);
    mx_strdel(&result2);

    const char *str3 = "TEST";
    const char *sub3 = "testing";
    const char *replace3 = "brave";
    char *result3 = mx_replace_substr(str3, sub3, replace3);
    printf("3.1. \'%s\'\t replace \'%s\' with \'%s\'\n3.2. \'%s\'\n", str3, sub3, replace3, result3);
    mx_strdel(&result3);

    const char *str4 = "Testing testing Testing test TEST retesting";
    const char *sub4 = "test";
    const char *replace4 = "RESULT";
    char *result4 = mx_replace_substr(str4, sub4, replace4);
    printf("4.1. \'%s\'\t replace \'%s\' with \'%s\'\n4.2. \'%s\'\n", str4, sub4, replace4, result4);
    mx_strdel(&result4);

    const char *str5 = "Ann";
    const char *sub5 = "Anna";
    const char *replace5 = "Ivanova";
    char *result5 = mx_replace_substr(str5, sub5, replace5);
    printf("4.1. \'%s\'\t replace \'%s\' with \'%s\'\n4.2. \'%s\'\n", str5, sub5, replace5, result5);
    mx_strdel(&result4);
//    system("leaks -q a.out");
//    Process 58598: 215 nodes malloced for 16 KB
//    Process 58598: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_mx_read_line(void) {
    printf("\nmx_read_line:\n");
    const char *file = "file.txt";
    int fd = open(file, O_RDONLY);
    if (fd >= 0) {
        char *line = NULL;
        size_t buf_size1 = 10;
        char delim1 = '\n';
        int bytes_read1 = mx_read_line(&line, buf_size1, delim1, fd);
        printf("1. Read line from \'%s\' (buf_size=%zu, delim=\'\\n\'):\n", file, buf_size1);
        if (bytes_read1 >= 0) {
            printf("res=%d\tstr=\"%s\"\n", bytes_read1, line);
            free(line);
        } else {
            printf("1. Failed to read line\n");
        }
        // res=8   str="FADE IN:"

        size_t buf_size2 = 35;
        char delim2 = 'a';
        int bytes_read2 = mx_read_line(&line, buf_size2, delim2, fd);
        printf("2. Read line from \'%s\' (buf_size=%zu, delim=\'a\'):\n", file, buf_size2);
        if (bytes_read2 >= 0) {
            printf("res=%d\tstr=\"%s\"\n", bytes_read2, line);
            free(line);
        } else {
            printf("2. Failed to read line\n");
        }
        // res=34  str="
        //ON COMPUTER SCREEN
        //
        //so close it h"

        size_t buf_size3 = 1;
        char delim3 = '.';
        int bytes_read3 = mx_read_line(&line, buf_size3, delim3, fd);
        printf("3. Read line from \'%s\' (buf_size=%zu, delim=\'.\'):\n", file, buf_size3);
        if (bytes_read3 >= 0) {
            printf("res=%d\tstr=\"%s\"\n", bytes_read3, line);
            free(line);
        } else {
            printf("3. Failed to read line\n");
        }
        //res=15  str="s no boundaries"

        size_t buf_size4 = 10;
        char delim4 = '\n';
        int bytes_read4 = mx_read_line(&line, buf_size4, delim4, fd);
        printf("4. Read line from \'%s\' (buf_size=%zu, delim=\'\\n\'):\n", file, buf_size4);
        if (bytes_read4 >= 0) {
            printf("res=%d\tstr=\"%s\"\n", bytes_read4, line);
            free(line);
        } else {
            printf("4. Failed to read line\n");
        }
        //res=0   str=""

        close(fd);
    } else {
        printf("Failed to open file: \'%s\'\n", file);
    }


    const char *file5 = "nonexistent.txt";
    int fd5 = open(file5, O_RDONLY);
    if (fd5 >= 0) {
        char *line5 = NULL;
        size_t buf_size5 = 10;
        char delim5 = '\n';
        int bytes_read5 = mx_read_line(&line5, buf_size5, delim5, fd5);
        printf("5. Read line from \'%s\' (buf_size=%zu, delim=\'%c\'):\n", file5, buf_size5, delim5);
        if (bytes_read5 >= 0) {
            printf("5. Line read (%d bytes): \"%s\"\n", bytes_read5, line5);
            free(line5);
        } else {
            printf("5. Failed to read line\n");
        }
        close(fd5);
    } else {
        printf("5. Failed to open file: \'%s\'\n", file5);
    }
    //5. Failed to open file: 'nonexistent.txt'
    printf("\n__________________________________\n");
}

void test_mx_memset(void) {
    printf("\nmx_memset:\n");
    char str[20] = "Hello, World!";
    printf("1. Initial string: \"%s\"\n", str);
    char *result = (char *)mx_memset(str, '*', 4);
    printf("1. Modified string: \"%s\"\n", result);

    char string[50] = "GeeksForGeeks is for programming geeks.";
    printf("\n2. Before memset(): %s\n", string);
    // Fill 8 characters starting from str[13] with '.'
    mx_memset(string + 13, '.', 8*sizeof(char));
    printf("2. After memset():  %s", string);
    printf("\n__________________________________\n");
}

void test_mx_memcpy(void) {
    printf("\nmx_memcpy:\n");
    char src[] = "This is the source string.";
    char dest[50];
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", dest, src, strlen(src) + 1);
    char *result = (char *) mx_memcpy(dest, src, strlen(src) + 1);
    printf("--->\tdst=\"%s\"\n", result); // n=27 dst="This is the source string."

    char str1[] = "Geeks";
    char str2[] = "Quiz";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str1, str2, sizeof(str2));
    mx_memcpy(str1, str2, sizeof(str2));
    printf("--->\tdst=\"%s\"\n", str1); // n=5 dst="Quiz"

    char str3[] = "Geeks";
    char str4[] = "";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str3, str4, sizeof(str4));
    mx_memcpy(str3, str4, sizeof(str4));
    printf("--->\tdst=\"%s\"\n", str3); // n=1 dst=""

    char str5[] = "Geeks";
    char str6[] = "test";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%d\t", str5, str6, 0);
    mx_memcpy(str5, str6, 0);
    printf("--->\tdst=\"%s\"\n", str5); // n=0 dst="Geeks"

    char str7[] = "GeeksGeeksGeeks";
    char str8[] = "TEST";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str7, str8, sizeof(str8) / 2);
    mx_memcpy(str7, str8, sizeof(str8) / 2);
    printf("--->\tdst=\"%s\"\n", str7); // n=2 dst="TEeksGeeksGeeks"

    char str9[] = "GeeksGeeksGeeks";
    char str10[] = "TEST";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str9, str10, sizeof(str10) * 2);
    mx_memcpy(str9, str10, sizeof(str10) * 2);
    printf("--->\tdst=\"%s\"\n", str9); // n=10 dst="TEST"
    printf("\n__________________________________\n");
}

void test_mx_memccpy(void) {
    printf("\nmx_memccpy:\n");
    char src[] = "This is the source string.";
    char dest[50];
    printf("1. src = \"%s\"\n", src);
    char *result = (char *) mx_memccpy(dest, src, 'i', strlen(src) + 1);
    if (result != NULL) {
        printf("Copied string until 'i' dst = \"%s\"\n", result);
    } else {
        printf("No 'i' found in the source string.\n");
    }
    // 1. src = "This is the source string."
    //Copied string until 'i' dst = "s is the source string."

    const char src2[] = "Stars: Altair, Sun, Vega.";
    const char terminal2[] = {':', ' ', ',', '.', '!'};
    char dest2[sizeof src2];
    const char alt2 = '@';
    printf("\n2. Initial str = \"%s\"\n", src2);
    for (size_t i = 0; i != sizeof terminal2; ++i) {
        void* to2 = mx_memccpy(dest2, src2, terminal2[i], sizeof dest2);
        printf("Char = '%c' (%s):\t\"", terminal2[i], to2 ? "found" : "absent");
        // if `terminal` character was not found - print the whole `dest`
        to2 = to2 ? to2 : dest2 + sizeof dest2;
        for (char* from2 = dest2; from2 != to2; ++from2) {
            if (*from2) {
                printf("%c", *from2);
            } else {
                printf("%c", alt2);
            }
        }
        puts("\"");
    }
    // 2. Initial str = "Stars: Altair, Sun, Vega."
    //Char = ':' (found):     "Stars:"
    //Char = ' ' (found):     "Stars: "
    //Char = ',' (found):     "Stars: Altair,"
    //Char = '.' (found):     "Stars: Altair, Sun, Vega."
    //Char = '!' (absent):    "Stars: Altair, Sun, Vega.@"

    puts("\n3. Star names with distances:");
    const char *star_distance[] = { "Arcturus : 37", "Vega : 25", "Capella : 43", "Rigel : 860", "Procyon : 11"};
    for (int i = 0; i < 5; ++i) {
        printf("\"%s\"\n",star_distance[i]);
    }
    char names_only[64];
    char *first = names_only;
    char *last = names_only + sizeof names_only;
    puts("\n" "Separate star names from distances (ly):");
    for (size_t t = 0; t != (sizeof star_distance) / (sizeof star_distance[0]); ++t) {
        if (first)
            first = mx_memccpy(first, star_distance[t], ' ', last - first);
        else
            break;
    }
    if (first) {
        *first = '\0';
        puts(names_only);
    } else {
        puts("Buffer is too small.");
    }
    // Star names with distances:
    //"Arcturus : 37"
    //"Vega : 25"
    //"Capella : 43"
    //"Rigel : 860"
    //"Procyon : 11"
    //
    //Separate star names from distances (ly):
    //Arcturus Vega Capella Rigel Procyon
    printf("\n__________________________________\n");
}

int demo(const char* lhs, const char* rhs, size_t sz) {
    for(size_t n = 0; n < sz; ++n)
        putchar(lhs[n]);

    int rc = mx_memcmp(lhs, rhs, sz);
    const char *rel = rc < 0 ? " precedes (-) " : rc > 0 ? " follows (+) " : " compares equal (0) ";
    fputs(rel, stdout);

    for(size_t n = 0; n < sz; ++n)
        putchar(rhs[n]);
    puts(" in lexicographical order = ");
    return rc;
}

void test_mx_memcmp(void) {
    printf("\nmx_memcmp:\n");
    char str1[] = "Hello, World!";
    char str2[] = "Hello,\tUniverse!";
    printf("str1 = \"%s\"\tstr2 = \"%s\"\n", str1, str2);
    int result = mx_memcmp(str1, str2, 7);
    printf("Comparison result for n=%d: %d\n", 7, result); // 23
    int result2 = mx_memcmp(str1, str2, 16);
    printf("Comparison result for n=%d: %d\n", 16, result2); // 23
    int result3 = mx_memcmp(str1, str2, 5);
    printf("Comparison result for n=%d: %d\n", 5, result3); // 0
    int result4 = mx_memcmp(str2, str1, 10);
    printf("Comparison result for n=%d: %d\n", 10, result4); // -23

    int demo (const char *lhs, const char *rhs, size_t sz);
    char a1[] = {'a','b','c'};
    char a2[sizeof a1] = {'a','b','d'};
    printf("%d\n", demo(a1, a2, sizeof a1));
    printf("%d\n", demo(a2, a1, sizeof a1));
    printf("%d\n", demo(a1, a1, sizeof a1));
    //abc precedes (-) abd in lexicographical order = -1
    //abd follows (+) abc in lexicographical order = 1
    //abc compares equal (0) abc in lexicographical order = 0
    printf("\n__________________________________\n");
}

void test_mx_memchr(void) {
    printf("\nmx_memchr:\n");
    char string[] = "This is a sample string.";
    printf("1. Initial str = \"%s\"\n", string);
    char *result = (char *) mx_memchr(string, 'a', strlen(string));
    if (result != NULL) {
        printf("Found 'a' at position %ld: \"%s\"\n", result - string, result);
    } else {
        printf("'a' not found in the string.\n");
    }
    //1. Initial str = "This is a sample string."
    //Found 'a' at position 8: "a sample string."


    const char str[] = "ABCDEFG\t@#$%^&*()\0!";
    const int chars[] = {'D', 'd', '!', 0, '\t', '\0'};
    printf("2. Initial str = \"%s\"\n", str);
    for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i) {
        const int c = chars[i];
        const char *ps = mx_memchr(str, c, strlen(str));
        ps ? printf ("character '%c'(%i) found at position %ld: \"%s\"\n", c, c, ps - str, ps)
           : printf ("character '%c'(%i) not found\n", c, c);
    }
    //2. Initial str = "ABCDEFG       @#$%^&*()"
    //character 'D'(68) found at position 3: "DEFG    @#$%^&*()"
    //character 'd'(100) not found
    //character '!'(33) not found
    //character ''(0) not found
    //character '     '(9) found at position 7: "     @#$%^&*()"
    //character ''(0) not found

    const char *str1 = "";
    const int chars1[] = {'D', '!', 0, '\0'};
    printf("3. Initial str = \"%s\"\n", str1);
    for (size_t i = 0; i < 4; ++i) {
        const int c = chars1[i];
        const char *ps = mx_memchr(str1, (int)c, strlen(str1));
        ps ? printf ("character '%c'(%i) found at position %ld: \"%s\"\n", c, c, ps - str1, ps)
           : printf ("character '%c'(%i) not found\n", c, c);
    }
    //3. Initial str = ""
    //character 'D'(68) not found
    //character '!'(33) not found
    //character ''(0) not found
    //character ''(0) not found
    printf("\n__________________________________\n");
}

void test_mx_memrchr(void) {
    printf("\nmx_memrchr:\n");
    char str_1[] = "Trinity";
    const char *res_1 = mx_memrchr(str_1, 'i', 7);
    printf("0. Initial str = \"%s\"\n", str_1);
    printf("Found \'i\' at position %ld, n=%d: \"%s\"\n", res_1 - str_1, 7, res_1);
    const char *res_2 = mx_memrchr(str_1, 'M', 7);
    printf("Found \'M\' at position %ld, n=%d: \"%s\"\n", res_2 - str_1, 7, res_2);
    const char *res_3 = mx_memrchr(str_1, 'i', 0);
    printf("Found \'i\' at position %ld, n=%d: \"%s\"\n", res_3 - str_1, 7, res_3);
    // 0. Initial str = "Trinity"
    //Found 'i' at position 4, n=7: "ity"
    //Found 'M' at position -6099727392, n=7: "(null)"
    //Found 'i' at position -6099727392, n=7: "(null)"
    char string[] = "This is a sample string.";
    printf("1. Initial str = \"%s\"\n", string);
    char *result = (char *) mx_memrchr(string, 's', strlen(string));
    if (result != NULL) {
        printf("Found \'s\' at position %ld: \"%s\"\n", result - string, result);
    } else {
        printf("\'s\' not found in the string.\n");
    }
    //1. Initial str = "This is a sample string."
    //Found 's' at position 17: "string."

    const char str[] = "ABCDEFG\t@#$%^&*()\0!";
    const int chars[] = {'D', 'd', '!', 0, '\t', '\0'};
    printf("2. Initial str = \"%s\"\n", str);
    for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i) {
        const int c = chars[i];
        const char *ps = mx_memrchr(str, c, strlen(str));
        ps ? printf ("character '%c'(%i) found at position %ld: \"%s\"\n", c, c, ps - str, ps)
           : printf ("character '%c'(%i) not found\n", c, c);
    }
    //2. Initial str = "ABCDEFG       @#$%^&*()"
    //character 'D'(68) found at position 3: "DEFG    @#$%^&*()"
    //character 'd'(100) not found
    //character '!'(33) not found
    //character ''(0) found at position 17: ""
    //character '     '(9) found at position 7: "     @#$%^&*()"
    //character ''(0) found at position 17: ""

    const char *str1 = "";
    const int chars1[] = {'D', '!', 0, '\0'};
    printf("3. Initial str = \"%s\"\n", str1);
    for (size_t i = 0; i < 4; ++i) {
        const int c = chars1[i];
        const char *ps = mx_memrchr(str1, (int)c, strlen(str1));
        ps ? printf ("character '%c'(%i) found at position %ld: \"%s\"\n", c, c, ps - str1, ps)
           : printf ("character '%c'(%i) not found\n", c, c);
    }
    //3. Initial str = ""
    //character 'D'(68) not found
    //character '!'(33) not found
    //character ''(0) not found
    //character ''(0) not found
    printf("\n__________________________________\n");
}

void test_mx_memmem(void) {
    printf("\nmx_memmem:\n");
    char big[] = "This is a big string for testing.";
    char little[] = "big string";
    printf("Initial string = \"%s\"\n", big);
    char *result = (char *) mx_memmem(big, mx_strlen(big), little, mx_strlen(little));
    if (result != NULL) {
        printf("Found 'big string' at position %ld:\t\"%s\"\n", result - big, result);
    } else {
        printf("'big string' not found in the big string.\n");
    }

    const char *haystack1 = "Hello, World!";
    const char *needle1 = "World";
    char *result1 = mx_memmem(haystack1, mx_strlen(haystack1), needle1, mx_strlen(needle1));
    printf("1. Substring found: \'%s\'\n", result1); //'World!'
    const char *haystack2 = "The quick brown fox";
    const char *needle2 = "lazy dog";
    char *result2 = mx_memmem(haystack2, mx_strlen(haystack2), needle2, mx_strlen(needle2));
    printf("2. Substring found: \'%s\'\n", result2); // '(null)'
    const char *str1 = "-0123456789 .";
    const char *str2 = "456";
    printf("3. memmem=\'%s\'\tmx_memmem=\'%s\'\n",
           (char *)memmem(str1, strlen(str1), str2, strlen(str2)),
           (char *)mx_memmem(str1, mx_strlen(str1), str2, mx_strlen(str2)));// '456789 .'
    const char str3[] = "TestjkbfkjsJHGCKGJHCQWERgvjhgj~";
    const char str4[] = "J";
    printf("4. position = %ld\tmemmem='%s'\tmx_memmem=\'%s\'\n",
           (char *)mx_memmem(str3, mx_strlen(str3), str4, mx_strlen(str4)) - str3,
           (char *)memmem(str3, strlen(str3), str4, strlen(str4)),
           (char *)mx_memmem(str3, strlen(str3), str4, strlen(str4))); // position = 11  'JHGCKGJHCQWERgvjhgj~'
    const char *str5 = "";
    printf("5. memmem=\'%s\'\tmx_memmem=\'%s\'\n",
           (char *)memmem(str3, strlen(str3), str5, strlen(str5)),
           (char *)mx_memmem(str3, mx_strlen(str3), str5, mx_strlen(str5)));// '(null)'
    const char *str6 = "ZaZ";
    printf("6. memmem=\'%s\'\tmx_memmem=\'%s\'\n",
           (char *)memmem(str3, strlen(str3), str6, strlen(str6)),
           (char *)mx_memmem(str3, mx_strlen(str3), str6, mx_strlen(str6)));// '(null)'
    printf("7. memmem=\'%s\'\tmx_memmem=\'%s\'\n",
           (char *)memmem(str5, strlen(str5), str6, strlen(str6)),
           (char *)mx_memmem(str5, mx_strlen(str5), str6, mx_strlen(str6)));// '(null)'
    printf("\n__________________________________\n");
}

void test_mx_memmove(void) {
    printf("\nmx_memmove:\n");
    char str[] = "This is a sample string.";
    printf("Initial str = \"%s\"\t", str);
    char *result1 = (char *) mx_memmove(str + 5, str, strlen(str) + 1);
    printf("New string: \"%s\"\n", result1); // Initial str = "This is a sample string." New string: "This is a sample string."

    char src[] = "This is the source string.";
    char dest[50];
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", dest, src, strlen(src) + 1);
    char *result = (char *) mx_memmove(dest, src, strlen(src) + 1);
    printf("--->\tdst=\"%s\"\n", result); // n=27 dst="This is the source string."

    char str1[] = "Geeks";
    char str2[] = "Quiz";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str1, str2, sizeof(str2));
    mx_memmove(str1, str2, sizeof(str2));
    printf("--->\tdst=\"%s\"\n", str1); // n=5 dst="Quiz"

    char str3[] = "Geeks";
    char str4[] = "";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str3, str4, sizeof(str4));
    mx_memmove(str3, str4, sizeof(str4));
    printf("--->\tdst=\"%s\"\n", str3); // n=1 dst=""

    char str5[] = "Geeks";
    char str6[] = "test";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%d\t", str5, str6, 0);
    mx_memmove(str5, str6, 0);
    printf("--->\tdst=\"%s\"\n", str5); // n=0 dst="Geeks"

    char str7[] = "GeeksGeeksGeeks";
    char str8[] = "TEST";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str7, str8, sizeof(str8) / 2);
    mx_memmove(str7, str8, sizeof(str8) / 2);
    printf("--->\tdst=\"%s\"\n", str7); // n=2 dst="TEeksGeeksGeeks"

    char str9[] = "GeeksGeeksGeeks";
    char str10[] = "TEST";
    printf("dst=\"%s\"\tsrc=\"%s\"\tn=%lu\t", str9, str10, sizeof(str10) * 2);
    mx_memmove(str9, str10, sizeof(str10) * 2);
    printf("--->\tdst=\"%s\"\n", str9); // n=10 dst="TEST"
    printf("\n__________________________________\n");
}

void test_mx_realloc(void) {
    printf("\nmx_realloc:\n");
    int *arr = (int *) malloc(5 * sizeof(int));
    printf("1. size of arr = %zu\tarr = ", malloc_size(arr) / sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
        printf("%d", arr[i]);
    }
    int *new_arr = (int *) mx_realloc(arr, 10 * sizeof(int));
    if (new_arr != NULL) {
        printf("\nReallocated array with size 10: \"");
        for (int i = 0; i < 10; i++) {
            printf("%d", new_arr[i]);
        }
        printf("\"\n");
        free(new_arr);
    } else {
        printf("\nFailed to reallocate array.\n");
        free(arr);
    }
    //1. size of arr = 8      arr = 01234
    //Reallocated array with size 10: "0123400000"


    int *arr2 = (int *) malloc(5 * sizeof(int));
    printf("2.  size of arr = %zu\tarr = ", malloc_size(arr2) / sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr2[i] = i;
        printf("%d", arr2[i]);
    }
    int *new_arr2 = (int *) mx_realloc(arr2, 0 * sizeof(int));
    if (new_arr2 != NULL) {
        printf("\nReallocated array with size 0: \"");
        for (int i = 0; i < 10; i++) {
            printf("%d", new_arr2[i]);
        }
        printf("\"\n");
        free(new_arr2);
    } else {
        printf("\nFailed to reallocate array.\n");
        free(arr2);
    }
    // 2.  size of arr = 8     arr = 01234
    //Reallocated array with size 0: "0123400000"

    int *arr3 = (int *) NULL;
    printf("3. size of arr = %zu\tarr = NULL", malloc_size(arr3) / sizeof(int));
//    for (int i = 0; i < 5; i++) {
//        arr3[i] = i;
//    }
    int *new_arr3 = (int *) mx_realloc(arr3, 10 * sizeof(int));
    if (new_arr3 != NULL) {
        printf("\nReallocated array with size 10: \"");
        for (int i = 0; i < 10; i++) {
            printf("%d", new_arr3[i]);
        }
        printf("\"\n");
        free(new_arr3);
    } else {
        printf("\nFailed to reallocate array.\n");
        free(arr3);
    }
    //3. size of arr = 0      arr = NULL
    //Reallocated array with size 10: "0000000000"

    int *arr4 = (int *) malloc(10 * sizeof(int));
    printf("4.  size of arr = %zu\tarr = ", malloc_size(arr4) / sizeof(int));
    for (int i = 0; i < 10; i++) {
        arr4[i] = i;
        printf("%d", arr4[i]);
    }
    int *new_arr4 = (int *) mx_realloc(arr4, 5 * sizeof(int));
    if (new_arr4 != NULL) {
        printf("\nReallocated array with size 5: \"");
        for (int i = 0; i < 5; i++) {
            printf("%d", new_arr4[i]);
        }
        printf("\"\n");
        free(new_arr4);
    } else {
        printf("\nFailed to reallocate array.\n");
        free(arr4);
    }
    //4.  size of arr = 12    arr = 0123456789
    //Reallocated array with size 5: "01234"
    //    system("leaks -q a.out");
    printf("\n__________________________________\n");
}



static void test_print_list(t_list *node){
    while (node != NULL){
        printf("%p ", node->data);
        node = node->next;
    }
}

void test_mx_create_node(void) {
    printf("\nmx_create_node:\n");
    int value = 42;
    t_list *node = mx_create_node(&value);
    if (node != NULL) {
        printf("Created node with value: %d\n", *(int *) (node->data)); // Created node with value: 42
        free(node);
    } else {
        printf("Failed to create node.\n");
    }

    t_list *head = NULL;
    t_list *second = NULL;
    t_list *third = NULL;
    head = mx_create_node(head);
    second = mx_create_node(second);
    third = mx_create_node(third);
    head->data = (void *) 1; // assign data in first node
    head->next = second; // Link first node with second
    second->data = (void *) 2; // assign data to second node
    second->next = third;
    third->data = (void *) 3; // assign data to third node
    third->next = NULL;
    printf("There is a list of nodes:");
    test_print_list(head); // There is a list of nodes:0x1 0x2 0x3
    printf("\n__________________________________\n");
}

static void test_print_list_data(t_list *list) {
    t_list *node = list;

    while (node != NULL) {
        write(1, node->data, mx_strlen((char *)node->data));
        mx_printchar(10);
        node = node->next;
    }
}

void test_mx_push_front(void) {
    printf("\nmx_push_front:\n");
    char str1[] = "1Hey!";
    char str2[] = "2Neo!";
    t_list *result = NULL;
    result = mx_create_node(str1);
    mx_push_front(&result, str2);
    test_print_list_data(result);
//    system("leaks -q a.out");
    //2Neo!
    //1Hey!
    //Process 94442: 217 nodes malloced for 16 KB
    //Process 94442: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_mx_push_back(void) {
    printf("\nmx_push_back:\n");
//    t_list *list = NULL;
//    int value1 = 1;
//    int value2 = 2;
//    int value3 = 3;
//    mx_push_back(&list, &value1);
//    mx_push_back(&list, &value2);
//    mx_push_back(&list, &value3);
//    printf("List size after pushing back 3 elements: %d\n", mx_list_size(list));

    char str1[] = "1Ay!";
    char str2[] = "2Ahoy!";
    char str3[] = "3Hey!";
    char str4[] = "4Hey, Neo!";
    char last_str[] = "5You are the chosen one!";
    t_list *res = NULL;
    mx_push_back(&res, str1);
    mx_push_back(&res, str2);
    mx_push_back(&res, str3);
    mx_push_back(&res, str4);
    printf("The list of data BEFORE pushing back:\n");
    //The list of data BEFORE pushing back:
    //1Ay!
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    test_print_list_data(res);
    mx_push_back(&res, last_str);
    printf("The list of data AFTER pushing back:\n");
    test_print_list_data(res);
    //The list of data AFTER pushing back:
    //1Ay!
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    //5You are the chosen one!
    printf("\n__________________________________\n");
}

void test_mx_pop_front(void) {
    printf("\nmx_pop_front:\n");
    t_list *list = NULL;
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    mx_push_back(&list, &value1);
    mx_push_back(&list, &value2);
    mx_push_back(&list, &value3);
    printf("1. List size BEFORE popping front: %d\n", mx_list_size(list));
    mx_pop_front(&list);
    printf("List size AFTER popping front: %d\n\n", mx_list_size(list));
    // 1. List size BEFORE popping front: 3
    //List size AFTER popping front: 2

    char str1[] = "1Ay!";
    char str2[] = "2Ahoy!";
    char str3[] = "3Hey!";
    char str4[] = "4Hey, Neo!";
    char last_str[] = "5You are the chosen one!";
    t_list *res = mx_create_node(str2);
    mx_push_back(&res, str3);
    mx_push_back(&res, str4);
    mx_push_back(&res, last_str);
    mx_push_front(&res, str1);
    printf("2. List size BEFORE popping front: %d\n", mx_list_size(res));
    test_print_list_data(res);
    mx_pop_front(&res);
    printf("List size AFTER popping front: %d\n", mx_list_size(res));
    test_print_list_data(res);
    //2. List size BEFORE popping front: 5
    //1Ay!
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    //5You are the chosen one!
    //List size AFTER popping front: 4
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    //5You are the chosen one!
//    system("leaks -q a.out");
    // Process 2686: 221 nodes malloced for 16 KB
    //Process 2686: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_mx_pop_back(void) {
    printf("\nmx_pop_back:\n");
    t_list *list = NULL;
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    mx_push_back(&list, &value1);
    mx_push_back(&list, &value2);
    mx_push_back(&list, &value3);
    printf("1. List size BEFORE popping back: %d\n", mx_list_size(list));
    mx_pop_back(&list);
    printf("List size AFTER popping back: %d\n\n", mx_list_size(list));
    //1. List size BEFORE popping back: 3
    //List size AFTER popping back: 2

    char str1[] = "1Ay!";
    char str2[] = "2Ahoy!";
    char str3[] = "3Hey!";
    char str4[] = "4Hey, Neo!";
    char last_str[] = "5You are the chosen one!";
    t_list *res = mx_create_node(str2);
    mx_push_back(&res, str3);
    mx_push_back(&res, str4);
    mx_push_back(&res, last_str);
    mx_push_front(&res, str1);
    printf("2. List size BEFORE popping back: %d\n", mx_list_size(res));
    test_print_list_data(res);
    mx_pop_back(&res);
    printf("List size AFTER popping back: %d\n", mx_list_size(res));
    test_print_list_data(res);
    //2. List size BEFORE popping back: 5
    //1Ay!
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    //5You are the chosen one!
    //List size AFTER popping back: 4
    //1Ay!
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
//    system("leaks -q a.out");
    //Process 3243: 221 nodes malloced for 16 KB
    //Process 3243: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_mx_list_size(void) {
    printf("\nmx_list_size:\n");
    t_list *list = NULL;
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    mx_push_back(&list, &value1);
    mx_push_back(&list, &value2);
    mx_push_back(&list, &value3);
    printf("1. List size: %d\n\n", mx_list_size(list));
    // 1. List size: 3

    char str1[] = "1Ay!";
    char str2[] = "2Ahoy!";
    char str3[] = "3Hey!";
    char str4[] = "4Hey, Neo!";
    char last_str[] = "5You are the chosen one!";
    t_list *res = mx_create_node(str2);
    printf("2. Initial List size: %d\n", mx_list_size(res));
    // 2. Initial List size: 1
    mx_push_back(&res, str3);
    mx_push_back(&res, str4);
    mx_push_back(&res, last_str);
    mx_push_front(&res, str1);
    printf("First List size: %d\n", mx_list_size(res));
    test_print_list_data(res);
    // First List size: 5
    //1Ay!
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    //5You are the chosen one!
    mx_pop_front(&res);
    printf("Second List size: %d\n", mx_list_size(res));
    test_print_list_data(res);
    // Second List size: 4
    //2Ahoy!
    //3Hey!
    //4Hey, Neo!
    //5You are the chosen one!
//    system("leaks -q a.out");
    // Process 3414: 222 nodes malloced for 16 KB
    //Process 3414: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

static bool test_compare_int(void *a, void *b) {
    int *int_a = (int *) a;
    int *int_b = (int *) b;
    return *int_a > *int_b;
}

static bool test_strcmp_bool(void *s1, void *s2) {
    char *char_s1 = (char *) s1;
    char *char_s2 = (char *) s2;
    while (*char_s1 != '\0'
           && *char_s1 == *char_s2) {
        char_s1++;
        char_s2++;
    }
    return *(unsigned char *)s1 > *(unsigned char *)s2;
}

void test_mx_sort_list(void) {
    printf("\nmx_sort_list:\n");
    t_list *list = NULL;
    int value1 = 3;
    int value2 = 1;
    int value3 = 2;
    mx_push_back(&list, &value1); // 3
    mx_push_back(&list, &value2); // 1
    mx_push_back(&list, &value3); // 3
    list = mx_sort_list(list, test_compare_int);
    printf("1. Sorted list values:\t");
    t_list *current = list;
    while (current != NULL) {
        printf("%d\t", *(int *) (current->data));
        current = current->next;
    }
    printf("\n\n");
    // 1. Sorted list values:  1       2       3

    char *s1 = "4", *s2 = "3", *s3 = "2", *s4 = "7";
    t_list *list1 = mx_create_node(s2);
    mx_push_front(&list1, s1);
    mx_push_back(&list1, s2);
    mx_push_back(&list1, s3);
    mx_push_front(&list1, s4);
    mx_push_back(&list1, "1");
    mx_push_back(&list1, "3");
    mx_push_back(&list1, "0");
    t_list *list1_copy = list1;
    mx_sort_list(list1, test_strcmp_bool);
    printf("2. Sorted list values:\t");
    while (list1 != NULL) {
        printf("%c\t", *(char *) (list1->data));
        list1 = list1->next;
    }
    printf("\n");
    //2. Sorted list values:  0       1       2       3       3       3       4       7
    while (list1_copy != NULL) {
        t_list *temp = list1_copy;
        list1_copy = list1_copy->next;
        free(temp);
    }
//    system("leaks -q a.out");
    // Process 10933: 218 nodes malloced for 16 KB
    //Process 10933: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

void test_list(void) {
    printf("\nLinked list tests:\n");
    t_list *list = mx_create_node("1");
    list->next = mx_create_node("2");
    mx_push_back(&list, "3");
    mx_push_front(&list, "0");
    printf("1. Size of list: %d\nData:\t", mx_list_size(list));
    for (t_list *l = list; l != NULL; l = l->next) {
        printf("\'%s\'\t", (char *) l->data);
    }
    printf("\n\n");
    //1. Size of list: 4
    //Data:   '0'     '1'     '2'     '3'
    mx_pop_front(&list);
    mx_pop_back(&list);
    mx_pop_front(&list);
    mx_pop_back(&list);
    printf("2. Size of list: %d\nData:\t", mx_list_size(list));
    for (t_list *l = list; l != NULL; l = l->next) {
        printf("\'%s\'\t", (char *) l->data);
    }
    printf("\n");
    // 2. Size of list: 0
    //Data:
//    system("leaks -q a.out");
    //Process 11266: 215 nodes malloced for 16 KB
    //Process 11266: 0 leaks for 0 total leaked bytes.
    printf("\n__________________________________\n");
}

int main(void) {
    // Utils pack (14)
    test_mx_printchar();
    test_mx_print_unicode();
    test_mx_printstr();
    test_mx_print_strarr();
    test_mx_printint();
    test_mx_pow();
    test_mx_sqrt();
    test_mx_nbr_to_hex();
    test_mx_hex_to_nbr();
    test_mx_itoa();
    test_mx_foreach();
    test_mx_binary_search();
    test_mx_bubble_sort();
    test_mx_quicksort();

    // String pack (23)
    test_mx_strlen();
    test_mx_swap_char();
    test_mx_str_reverse();
    test_mx_strdel();
    test_mx_del_strarr();
    test_mx_get_char_index();
    test_mx_strdup();
    test_mx_strndup();
    test_mx_strcpy();
    test_mx_strncpy();
    test_mx_strcmp();
    test_mx_strcat();
    test_mx_strncmp(); // todo custom
    test_mx_strchr(); //todo custom
    test_mx_strstr();
    test_mx_get_substr_index();
    test_mx_count_substr();
    test_mx_count_words();
    test_mx_strnew();
    test_mx_strtrim();
    test_mx_del_extra_spaces();
    test_mx_strsplit();
    test_mx_strjoin();
    test_mx_file_to_str();
    test_mx_replace_substr();
    test_mx_read_line();

    // Memory pack (9)
    test_mx_memset();
    test_mx_memcpy();
    test_mx_memccpy();
    test_mx_memcmp();
    test_mx_memchr();
    test_mx_memrchr();
    test_mx_memmem();
    test_mx_memmove();
    test_mx_realloc();

    // List pack (7)
    test_mx_create_node();
    test_mx_push_front();
    test_mx_push_back();
    test_mx_pop_front();
    test_mx_pop_back();
    test_mx_list_size();
    test_mx_sort_list();
    test_list();
    return 0;
}

