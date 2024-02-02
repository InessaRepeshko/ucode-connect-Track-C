#include "uls.h"

bool compare_strings(void *data1, void *data2) {
    return mx_strcmp(data1, data2) > 0;
}

void sort_objects_names(t_list *objects_names, t_sort_type sort_type) {
    if (sort_type != SORT_NONE) {
        mx_sort_list_objects(objects_names, compare_strings, false);
    }
}

bool compare_objects_by_name(void *data1, void *data2) {
    t_object_info *object_info1 = data1;
    t_object_info *object_info2 = data2;

    return mx_strcmp(object_info1->name, object_info2->name) > 0;
}

bool compare_objects_by_time(void *data1, void *data2) {
    t_object_info *object_info1 = data1;
    t_object_info *object_info2 = data2;

    if (object_info1->timespec.tv_sec == object_info2->timespec.tv_sec) {
        if (object_info1->timespec.tv_nsec == object_info2->timespec.tv_nsec) {
            return mx_strcmp(object_info1->name, object_info2->name) > 0;
        }

        return object_info1->timespec.tv_nsec < object_info2->timespec.tv_nsec;
    }

    return object_info1->timespec.tv_sec < object_info2->timespec.tv_sec;
}

bool compare_objects_by_size(void *data1, void *data2) {
    t_object_info *object_info1 = data1;
    t_object_info *object_info2 = data2;

    if (object_info1->stat.st_size == object_info2->stat.st_size) {
        return mx_strcmp(object_info1->name, object_info2->name) > 0;
    }

    return object_info1->stat.st_size < object_info2->stat.st_size;
}

void sort_objects_info(t_list *objects_info, t_sort_type sort_type, bool reverse) {
    switch (sort_type) {
    case SORT_BY_NAME:
        mx_sort_list_objects(objects_info, compare_objects_by_name, reverse);
        break;

    case SORT_BY_TIME:
        mx_sort_list_objects(objects_info, compare_objects_by_time, reverse);
        break;

    case SORT_BY_SIZE:
        mx_sort_list_objects(objects_info, compare_objects_by_size, reverse);
        break;

    default:
        break;
    }
}

