//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_strlen.c mx_printstr.c -o output
//./output

int mx_strlen(const char *s);
void mx_printstr(const char *s);

int main(void) {
    const char *str = "Hello, World!";
    mx_printstr(str);

    return 0;
}

