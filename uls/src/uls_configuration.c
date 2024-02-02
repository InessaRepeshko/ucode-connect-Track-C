#include "uls.h"

t_config *create_config(void) {
    t_config *config = malloc(sizeof(t_config));
    mx_memset(config, 0, sizeof(t_config));

    if (isatty(1)) {
        config->format = MULTICOLUMN_FORMAT;
    }

    return config;
}

t_config *read_args(int argc, char *argv[]) {
    t_config *config = create_config();

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            break;
        }

        for (char *str = argv[i] + 1; *str != '\0'; str++) {
            switch (*str) {
            case 'R':
                config->recursive = true;
                break;

            case 'G':
                config->colorize = true;
                break;

            case 'F':
                config->classify = true;
                config->slash = false;
                break;

            case 'p':
                config->slash = true;
                config->classify = false;
                break;

            case 'r':
                config->reverse_sort = true;
                break;

            case 'h':
                config->human_readable = true;
                break;

            case 'e':
                config->access_control_list = true;
                break;

            case 'T':
                config->complete_time_info = true;
                break;

            case '@':
                config->extended_attribute_keys = true;
                break;

            case 'g':
                config->omit_owner = true;
                break;

            case 'o':
                config->omit_group = true;
                break;

            case 'x':
                config->sort_across = true;
                break;

            case 'n':
                config->display_numeric_ids = true;
                break;

            case 'q':
                config->replace_non_graphic = true;
                break;

            case 'H':
                config->symbolic_links = true;
                break;

            case '1':
                config->format = SINGLECOLUMN_FORMAT;
                break;

            case 'C':
                config->format = MULTICOLUMN_FORMAT;
                break;

            case 'm':
                config->format = STREAM_FORMAT;
                break;

            case 'l':
                config->format = LONG_FORMAT;
                break;

            case 'c':
                config->time_type = STATUS_CHANGE_TIME;
                break;

            case 'u':
                config->time_type = ACCESS_TIME;
                break;

            case 'U':
                config->time_type = CREATION_TIME;
                break;

            case 't':
                config->sort_type = SORT_BY_TIME;
                break;

            case 'S':
                config->sort_type = SORT_BY_SIZE;
                break;

            case 'f':
                config->sort_type = SORT_NONE;
                config->ignore_type = IGNORE_NONE;
                break;

            case 'A':
                config->ignore_type = IGNORE_DOTS;
                break;

            case 'a':
                config->ignore_type = IGNORE_NONE;
                break;

            default:
                mx_printerr("uls: illegal option -- ");
                write(2, str, 1);
                write(2, "\n", 1);
                mx_printerr("usage: uls [-@ACFGHRSTUacefghlmnopqrtux1] [file ...]\n");
                exit(1);
            }
        }
    }

    if (!isatty(1)) {
        config->colorize = false;
    } else {
        config->replace_non_graphic = true;
    }

    if (!config->symbolic_links) {
        config->symbolic_links =
                config->format != LONG_FORMAT
                && !config->colorize
                && !config->classify;
    }

    if (config->sort_type == SORT_NONE) {
        config->ignore_type = IGNORE_NONE;
    }

    return config;
}

