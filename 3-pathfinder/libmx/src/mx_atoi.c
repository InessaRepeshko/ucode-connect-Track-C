#include "libmx.h"

static bool mx_overflow_with_addition(long *buff, long num) {
    long temp = 9223372036854775807 - num;

    if (temp < *buff) {
        return true;
    }

    *buff += num;

    return false;
}

static bool mx_overflow_with_multiplication(long *buff, long num) {
    long temp = 9223372036854775807 / num;

    if (temp < *buff) {
        return true;
    }

    *buff *= num;

    return false;
}

int mx_atoi(const char *str, int *number) {
    long buffer = 0;
    bool negative = false;

    if (*str == 45
        || *str == 43) {
        if (*str == 45) {
            negative = true;
        }

        str++;
    }

    while (mx_isdigit(*str)) {
        if (mx_overflow_with_multiplication(&buffer, 10)
            || mx_overflow_with_addition(&buffer, (*str - 48))) {
            if (negative) {
                *number = 0;
            } else {
                *number = -1;
            }

            return -1;
        }

        str++;
    }

    if (*str != '\0') {
        return -1;
    }

    if (negative) {
        *number = -buffer;
    } else {
        *number = buffer;
    }

    return 0;
}

