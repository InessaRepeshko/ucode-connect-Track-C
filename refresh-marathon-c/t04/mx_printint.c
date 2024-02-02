void mx_printchar(char c);

void mx_printint(int n) {
    char a[102];
    long num = n;
    int i = 0;

    if (num < 0) {
        num *= -1;
        mx_printchar(45);
    }

    if (num == 0) {
        mx_printchar(n + 48);
    }

    while (num != 0) {
        a[i++] = (num % 10) + 48;
        num /= 10;
    }

    for (int j = i - 1; j >= 0; j--) {
        mx_printchar(a[j]);
    }
}

