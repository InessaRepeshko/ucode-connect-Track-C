// clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_hex_to_nbr.c -o output
//./output
//https://www.rapidtables.com/convert/number/hex-to-decimal.html

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

unsigned long mx_hex_to_nbr(const char *hex);

int main(void) {
    const char *hex0 = "C4"; // returns 196
    printf("0: hex=\"%s\"\t\t\tdec=%lu\n", hex0, mx_hex_to_nbr(hex0));

    const char *hex1 = "FADE"; // returns 64222
    printf("1: hex=\"%s\"\t\t\tdec=%lu\n", hex1, mx_hex_to_nbr(hex1));

    const char *hex2 = "ffffffffffff"; // returns 281474976710655
    printf("2: hex=\"%s\"\t\tdec=%lu\n", hex2, mx_hex_to_nbr(hex2));

    const char *hex3 = "\'!@-FA_de!"; // returns 0
    printf("3: hex=\"%s\"\t\tdec=%lu\n", hex3, mx_hex_to_nbr(hex3));

    const char *hex4 = "--- -+-59 "; // returns 0
    printf("4: hex=\"%s\"\t\tdec=%lu\n", hex4, mx_hex_to_nbr(hex4));

    const char *hex5 = "-A"; // -10, returns 0
    printf("5: hex=\"%s\"\t\t\tdec=%lu\n", hex5, mx_hex_to_nbr(hex5));

    const char *hex6 = "8000000000000002"; // returns 9223372036854775810
    printf("6: hex=\"%s\"\tdec=%lu\n", hex6, mx_hex_to_nbr(hex6));

    const char *hex7 = "1000000000000000A"; // returns 10
    // 18446744073709551626 > 18446744073709551615 (unsigned long max 8-byte) by 11
    printf("7: hex=\"%s\"\tdec=%lu\n", hex7, mx_hex_to_nbr(hex7));

    return 0;
}

