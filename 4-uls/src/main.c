#include "uls.h"

t_list *get_list_of_objects(int argc, char *argv[]) {
    t_list *objects = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-'
            || objects != NULL) {
            mx_push_back(&objects, argv[i]);
        }
    }

    if (objects == NULL) {
        mx_push_back(&objects, ".");
    }

    return objects;
}

void print_error(const char *filename) {
    mx_printerr("uls: ");
    mx_printerr(filename);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

void clear_list_of_objects(t_list *objects_info) {
    t_list *temp = objects_info;

    while (temp != NULL) {
        t_object_info *object_info = temp->data;
        clear_object_info(object_info);
        temp = temp->next;
    }

    mx_clear_list(&objects_info);
}

void print_files_info(t_list *files, t_config *config) {
    if (files != NULL) {
        sort_objects_info(files, config->sort_type, config->reverse_sort);
        print_objects_info_in_format(files, config);
    }
}

bool print_directory_info(t_object_info *object_info, t_config *config, bool print_object_name) {
    if (print_object_name) {
        mx_printstr(object_info->name);
        mx_printstr(":\n");
    }

    t_list *objects_info = NULL;
    bool status = read_directory_data(&objects_info, object_info->path, config);

    if (config->format == LONG_FORMAT
        && objects_info != NULL) {
        mx_printstr("total ");
        mx_printint(count_blocks_for_objects(objects_info));
        mx_printchar('\n');
    }

    if (!status) {
        print_error(object_info->name);
        return false;
    }

    sort_objects_info(objects_info, config->sort_type, config->reverse_sort);
    print_objects_info_in_format(objects_info, config);

    if (config->recursive) {
        t_list *directories = NULL;

        while (objects_info != NULL) {
            t_object_info *entry = objects_info->data;

            if (S_ISDIR(entry->stat.st_mode)
                && !is_hidden_object(entry->name, IGNORE_DOTS)) {
                free(entry->name);
                entry->name = mx_strdup(entry->path);
                mx_push_back(&directories, entry);
            }

            objects_info = objects_info->next;
        }

        if (directories != NULL) {
            mx_printchar('\n');
        }

        if (!print_directories_info(directories, config, true)) {
            status = false;
        }

        mx_clear_list(&directories);
    }

    clear_list_of_objects(objects_info);

    return status;
}

bool print_directories_info(t_list *directories, t_config *config, bool print_objects_names) {
    bool ret = true;
    sort_objects_info(directories, config->sort_type, config->reverse_sort);

    while (directories != NULL) {
        t_object_info *object_info = directories->data;

        if (!print_directory_info(object_info, config, print_objects_names)) {
            ret = false;
        }

        if (directories->next != NULL) {
            mx_printchar('\n');
        }

        directories = directories->next;
    }

    return ret;
}

int print_objects_info(t_list *objects, t_config *config) {
    t_list *files = NULL;
    t_list *directories = NULL;
    bool print_objects_names = mx_list_size(objects) > 1;
    int status = 0;
    sort_objects_names(objects, config->sort_type);

    while (objects != NULL) {
        char *object = objects->data;
        objects = objects->next;
        t_object_info *object_info = set_object_info(NULL, object, config);

        if (object_info == NULL) {
            print_error(object);
            status = 1;
            continue;
        }

        if (S_ISDIR(object_info->stat.st_mode)) {
            mx_push_back(&directories, object_info);
        } else {
            mx_push_back(&files, object_info);
        }
    }

    print_files_info(files, config);

    if (files != NULL
        && directories != NULL) {
        mx_printchar('\n');
    }

    if (!print_directories_info(directories, config, print_objects_names)) {
        status = 1;
    }

    clear_list_of_objects(files);
    clear_list_of_objects(directories);

    return status;
}

int main(int argc, char *argv[]) {
    t_list *objects = get_list_of_objects(argc, argv);
    t_config *config = read_args(argc, argv);
    int status = print_objects_info(objects, config);
    mx_clear_list(&objects);
    free(config);

    return status;
}

