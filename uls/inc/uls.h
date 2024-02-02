#ifndef ULS_H
#define ULS_H

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/syslimits.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>
#include "libmx.h"

/* uls configuration pack */
typedef enum {
    SINGLECOLUMN_FORMAT,    // -1
    MULTICOLUMN_FORMAT,     // -C
    STREAM_FORMAT,          // -m
    LONG_FORMAT,            // -l
} t_format;

typedef enum {
    MODIFICATION_TIME,      // default
    STATUS_CHANGE_TIME,     // -c
    ACCESS_TIME,            // -u
    CREATION_TIME,          // -U
} t_time_type;

typedef enum {
    SORT_BY_NAME,           // default
    SORT_BY_TIME,           // -t
    SORT_BY_SIZE,           // -S
    SORT_NONE,              // -f
} t_sort_type;

typedef enum {
    IGNORE_HIDDEN,          // default
    IGNORE_DOTS,            // -A
    IGNORE_NONE,            // -a
} t_ignore_type;

typedef struct {
    t_format format;
    t_time_type time_type;
    t_sort_type sort_type;
    t_ignore_type ignore_type;
    bool recursive;                 // -R
    bool colorize;                  // -G
    bool classify;                  // -F
    bool slash;                     // -p
    bool reverse_sort;              // -r
    bool human_readable;            // -h
    bool access_control_list;       // -e
    bool complete_time_info;        // -T
    bool extended_attribute_keys;   // -@
    bool omit_owner;                // -g
    bool omit_group;                // -o
    bool sort_across;               // -x
    bool display_numeric_ids;       // -n
    bool replace_non_graphic;       // -q
    bool symbolic_links;            // -H
} t_config;

t_config *create_config(void);
t_config *read_args(int argc, char *argv[]);

/* Objects (files and directories) information pack */
typedef struct {
    char *path;
    char *name;
    char *user;
    char *link;
    char *group;
    char **xattr_keys;
    acl_t acl;
    struct stat stat;
    struct timespec timespec;
} t_object_info;

char *get_user_data(uid_t uid, bool numeric);
char *get_group_data(gid_t gid, bool numeric);
struct timespec get_time_data(struct stat *stat, t_time_type time_type);
char **get_xattr_data(const char *filename);
t_object_info *set_object_info(const char *directory, const char *name, t_config *config);
bool is_hidden_object(const char *name, t_ignore_type ignore_type);
bool read_directory_data(t_list **objects, const char *name, t_config *config);
void clear_object_info(t_object_info *object_info);
blkcnt_t count_blocks_for_objects(t_list *objects);

/* File information sorting pack */
bool compare_strings(void *data1, void *data2);
void sort_objects_names(t_list *objects_names, t_sort_type sort_type);
bool compare_objects_by_name(void *data1, void *data2);
bool compare_objects_by_time(void *data1, void *data2);
bool compare_objects_by_size(void *data1, void *data2);
void sort_objects_info(t_list *objects_info, t_sort_type sort_type, bool reverse);

/* Outputs packages */
typedef struct {
    int links;
    int user;
    int group;
    int size;
} t_width;

/* Formatted output pack */
void print_color_scheme(mode_t mode);
int print_object_classifier(mode_t mode, bool slash_only);
char *replace_non_graphic_chars(const char *name);
void print_object_name(const char *name, bool replace_non_graphic);
int print_object_info(t_object_info *object_info, t_config *config);
void print_objects_info_to_single_column(t_list *objects_info, t_config *config);
void print_objects_info_to_stream(t_list *objects_info, t_config *config);
void print_objects_info_in_format(t_list *objects_info, t_config *config);

/* Long formatted output pack */
void print_object_type_data(mode_t mode);
void print_object_permissions_data(mode_t mode);
void print_aligned_string(char *string, int width, bool align_right);
void print_aligned_llnumber(long long number, int width);
void print_object_time_data(time_t ptime, bool full);
double round_dnumber(double number);
void print_aligned_object_size_data(off_t size, int width);
void print_object_xattr_data(t_object_info *object_info, bool human_readable);
void print_object_acl_data(acl_t acl);
void print_aligned_object_info_in_long_format(t_object_info *object_info, t_width *width, t_config *config);
t_width find_max_width_for_long_format(t_list *objects_info, t_config *config);
void print_objects_info_in_long_format(t_list *objects_info, t_config *config);

/* Multicolumn formatted output pack */
int find_max_width_for_multicolumn_format(t_list *objects_info);
int find_terminal_window_width(void);
void print_tab_aligned_columns(int width, int tab_width);
t_object_info **convert_list_to_array(t_list *objects_info, int *count);
void print_objects_data_in_multicolumn_format(t_list *objects_info, t_config *config);

/* uls main pack */
t_list *get_list_of_objects(int argc, char *argv[]);
void print_error(const char *filename);
void clear_list_of_objects(t_list *objects_info);
void print_files_info(t_list *files, t_config *config);
bool print_directory_info(t_object_info *object_info, t_config *config, bool print_object_name);
bool print_directories_info(t_list *directories, t_config *config, bool print_objects_names);
int print_objects_info(t_list *objects, t_config *config);

#endif

