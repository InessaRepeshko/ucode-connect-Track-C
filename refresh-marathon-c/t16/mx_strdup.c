int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str) {
    char *dst = mx_strnew(mx_strlen(str));

    if (dst) {
        mx_strcpy(dst, str);
    }

    return dst;
}

