void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

void sort_args(int argc, char *argv[]) {
    for (int i = 1; i < argc - 1; i++) {
        for (int j = i + 1; j < argc; j++) {
            if (mx_strcmp(argv[i], argv[j]) > 0) {
                char *temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    sort_args(argc, argv);

    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar(10);
    }

    return 0;
}

