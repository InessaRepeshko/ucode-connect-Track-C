#include "uls.h"

void print_color_scheme(mode_t mode) {
    switch (mode & S_IFMT) {
    case S_IFBLK:
        mx_printstr("\033[34;46m");
        break;

    case S_IFCHR:
        mx_printstr("\033[34;43m");
        break;

    case S_IFDIR:
        if (mode & S_IWOTH) {
            if (mode & S_ISTXT) {
                mx_printstr("\033[30;42m");
            } else {
                mx_printstr("\033[30;43m");
            }
        } else {
            mx_printstr("\033[34m");
        }
        break;

    case S_IFIFO:
        mx_printstr("\033[33m");
        break;

    case S_IFLNK:
        mx_printstr("\033[35m");
        break;

    case S_IFSOCK:
        mx_printstr("\033[32m");
        break;

    default:
        if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            if (mode & S_ISUID) {
                mx_printstr("\033[30;41m");
            } else if (mode & S_ISGID) {
                mx_printstr("\033[30;46m");
            } else {
                mx_printstr("\033[31m");
            }
        }
        break;
    }
}

int print_object_classifier(mode_t mode, bool slash_only) {
    char classifier = '\0';

    switch (mode & S_IFMT) {
    case S_IFDIR:
        classifier = '/';
        break;

    case S_IFIFO:
        classifier = '|';
        break;

    case S_IFLNK:
        classifier = '@';
        break;

    case S_IFSOCK:
        classifier = '=';
        break;

    case S_IFREG:
        if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            classifier = '*';
        }
        break;
    }

    if (classifier != '\0') {
        if (slash_only
            && classifier != '/') {
            return 0;
        }

        mx_printchar(classifier);

        return 1;
    }

    return 0;
}

char *replace_non_graphic_chars(const char *name) {
    char *copy = mx_strdup(name);

    for (int i = 0; copy[i] != '\0'; i++) {
        if (copy[i] >= 0
            && copy[i] <= 31) {
            copy[i] = '?';
        }
    }

    return copy;
}

void print_object_name(const char *name, bool replace_non_graphic) {
    if (replace_non_graphic) {
        char *str = replace_non_graphic_chars(name);
        mx_printstr(str);
        free(str);
    } else {
        mx_printstr(name);
    }
}

int print_object_info(t_object_info *object_info, t_config *config) {
    if (config->colorize) {
        print_color_scheme(object_info->stat.st_mode);
    }

    print_object_name(object_info->name, config->replace_non_graphic);

    if (config->colorize) {
        mx_printstr("\033[0m");
    }

    int count = mx_strlen(object_info->name);

    if (config->classify
        || config->slash) {
        count += print_object_classifier(object_info->stat.st_mode, config->slash);
    }

    return count;
}

void print_objects_info_to_single_column(t_list *objects_info, t_config *config) {
    while (objects_info != NULL) {
        print_object_info(objects_info->data, config);
        mx_printchar('\n');
        objects_info = objects_info->next;
    }
}

void print_objects_info_to_stream(t_list *objects_info, t_config *config) {
    while (objects_info != NULL) {
        print_object_info(objects_info->data, config);

        if (objects_info->next != NULL) {
            mx_printstr(", ");
        }

        objects_info = objects_info->next;
    }

    mx_printchar('\n');
}

void print_objects_info_in_format(t_list *objects_info, t_config *config) {
    switch (config->format) {
    case SINGLECOLUMN_FORMAT:
        print_objects_info_to_single_column(objects_info, config);
        break;

    case MULTICOLUMN_FORMAT:
        print_objects_data_in_multicolumn_format(objects_info, config);
        break;

    case STREAM_FORMAT:
        print_objects_info_to_stream(objects_info, config);
        break;

    case LONG_FORMAT:
        print_objects_info_in_long_format(objects_info, config);
        break;

    default:
        break;
    }
}

