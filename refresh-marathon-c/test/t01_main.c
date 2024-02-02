//clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c mx_printchar.c mx_print_alphabet.c -o output
//./output

void mx_printchar(char c);
void mx_print_alphabet(void);

int main(void) {
    mx_print_alphabet();
    return 0;
}

