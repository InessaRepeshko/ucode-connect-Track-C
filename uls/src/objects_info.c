#include "uls.h"

char *get_user_data(uid_t uid, bool numeric) {
    struct passwd *passwd = getpwuid(uid);

    if (passwd == NULL
        || numeric) {
        return mx_lltoa(uid);
    }

    return mx_strdup(passwd->pw_name);
}

char *get_group_data(gid_t gid, bool numeric) {
    struct group *group = getgrgid(gid);

    if (group == NULL
        || numeric) {
        return mx_lltoa(gid);
    }

    return mx_strdup(group->gr_name);
}

struct timespec get_time_data(struct stat *stat, t_time_type time_type) {
    switch (time_type) {
    case MODIFICATION_TIME:
        return stat->st_mtimespec;

    case STATUS_CHANGE_TIME:
        return stat->st_ctimespec;

    case ACCESS_TIME:
        return stat->st_atimespec;

    case CREATION_TIME:
        return stat->st_birthtimespec;

    default:
        break;
    }
}

char **get_xattr_data(const char *filename) {
    char buffer[1024] = {'\0'};
    ssize_t count = listxattr(filename, buffer, sizeof(buffer), XATTR_NOFOLLOW);

    for (int i = 0; i < count - 1; i++) {
        if (buffer[i] == '\0') {
            buffer[i] = ':';
        }
    }

    if (count > 0) {
        return mx_strsplit(buffer, ':');
    }

    return NULL;
}

t_object_info *set_object_info(const char *directory, const char *name, t_config *config) {
    t_object_info *object_info = malloc(sizeof(t_object_info));
    object_info->path = mx_strjoin_with_delim(directory, name, '/');
    object_info->name = mx_strdup(name);
    object_info->user = NULL;
    object_info->link = NULL;
    object_info->group = NULL;
    object_info->xattr_keys = NULL;
    object_info->acl = NULL;
    int err;

    if (directory == NULL
        && config->symbolic_links) {
        err = stat(object_info->path, &object_info->stat);
    } else {
        err = lstat(object_info->path, &object_info->stat);
    }

    if (err != 0) {
        clear_object_info(object_info);
        return NULL;
    }

    if (config->format == LONG_FORMAT) {
        object_info->user = get_user_data(object_info->stat.st_uid, config->display_numeric_ids);
        object_info->group = get_group_data(object_info->stat.st_gid, config->display_numeric_ids);

        if (S_ISLNK(object_info->stat.st_mode)) {
            object_info->link = malloc(PATH_MAX);
            ssize_t size = readlink(object_info->path, object_info->link, PATH_MAX);
            object_info->link[size] = '\0';
        } else {
            object_info->link = NULL;
            object_info->acl = acl_get_file(object_info->path, ACL_TYPE_EXTENDED);
        }

        object_info->xattr_keys = get_xattr_data(object_info->path);
    }

    object_info->timespec = get_time_data(&object_info->stat, config->time_type);

    return object_info;
}

bool is_hidden_object(const char *name, t_ignore_type ignore_type) {
    if (ignore_type == IGNORE_HIDDEN
        && name[0] == '.') {
        return true;
    }

    if (ignore_type == IGNORE_DOTS
        && (mx_strcmp(name, ".") == 0
        || mx_strcmp(name, "..") == 0)) {
        return true;
    }

    return false;
}

bool read_directory_data(t_list **objects, const char *name, t_config *config) {
    DIR *directory = opendir(name);
    struct dirent *object = NULL;

    if (directory == NULL) {
        return false;
    }

    while ((object = readdir(directory)) != NULL) {
        if (!is_hidden_object(object->d_name, config->ignore_type)) {
            mx_push_back(objects, set_object_info(name, object->d_name, config));
        }
    }

    closedir(directory);

    return true;
}

void clear_object_info(t_object_info *object_info) {
    free(object_info->path);
    free(object_info->name);
    mx_strdel(&object_info->user);
    mx_strdel(&object_info->link);
    mx_strdel(&object_info->group);
    mx_del_strarr(&object_info->xattr_keys);
    acl_free(object_info->acl);
    free(object_info);
}

blkcnt_t count_blocks_for_objects(t_list *objects) {
    t_list *current = objects;
    blkcnt_t blocks = 0;

    while (current != NULL) {
        t_object_info *object_info = current->data;

        blocks += object_info->stat.st_blocks;
        current = current->next;
    }

    return blocks;
}

