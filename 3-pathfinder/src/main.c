#include "pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }

    if (!verify_file_exists(argv[1])) {
        print_error_message(FILE_DOES_NOT_EXIST, argv[1]);
        return 0;
    }

    if (verify_file_is_empty(argv[1])) {
        print_error_message(FILE_IS_EMPTY, argv[1]);
        return 0;
    }

    int fd = open(argv[1], O_RDONLY);
    t_graph *graph = parse_file(fd);

    if (graph == NULL) {
        return 0;
    }

    print_all_paths(graph);
    delete_graph_data(graph);
}

