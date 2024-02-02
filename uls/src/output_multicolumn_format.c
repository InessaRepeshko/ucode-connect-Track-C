#include "uls.h"

int find_max_width_for_multicolumn_format(t_list *objects_info) {
    int width = 0;

    while (objects_info != NULL) {
        t_object_info *object_info = objects_info->data;
        int len = mx_strlen(object_info->name);

        if (width < len) {
            width = len;
        }

        objects_info = objects_info->next;
    }

    return width;
}

int find_terminal_window_width(void) {
    if (isatty(1)) {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        return w.ws_col;
    }

    return 80;
}

void print_tab_aligned_columns(int width, int tab_width) {
    int tabs = (width + tab_width - 1) / tab_width;

    for (int i = 0; i < tabs; i++) {
        if (tab_width == 1) {
            mx_printchar(' ');
        } else {
            mx_printchar('\t');
        }
    }
}

t_object_info **convert_list_to_array(t_list *objects_info, int *count) {
    *count = mx_list_size(objects_info);

    if (count == 0) {
        return NULL;
    }

    t_object_info **array = malloc(sizeof(t_object_info *) * (*count));

    for (int i = 0; i < *count; i++) {
        array[i] = objects_info->data;
        objects_info = objects_info->next;
    }

    return array;
}

void print_objects_data_in_multicolumn_format(t_list *objects_info, t_config *config) {
    int tab_width = 8;

    if (config->colorize) {
        tab_width = 1;
    }

    int width = find_max_width_for_multicolumn_format(objects_info);

    if (config->classify || config->slash) {
        width++;
    }

    width = (width + tab_width) & ~(tab_width - 1);

    int num_cols = find_terminal_window_width() / width;

    if (num_cols <= 1) {
        print_objects_info_to_single_column(objects_info, config);
        return;
    }

    int count;
    t_object_info **array = convert_list_to_array(objects_info, &count);
    int num_rows = (count + num_cols - 1) / num_cols;
    int idx = 0;

    for (int i = 0; i < num_rows; i++) {
        if (!config->sort_across) {
            idx = i;
        }

        for (int j = 0; j < num_cols; j++) {
            int printed = print_object_info(array[idx], config);

            if (config->sort_across) {
                idx++;
            } else {
                idx += num_rows;
            }

            if (idx >= count) {
                break;
            }

            print_tab_aligned_columns(width - printed, tab_width);
        }

        mx_printchar('\n');
    }

    if (array != NULL) {
        free(array);
    }
}

