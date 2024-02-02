#include "pathfinder.h"

bool verify_file_exists(const char *name) {
    int fd = open(name, O_RDONLY);

    if (fd == -1) {
        return false;
    }

    close(fd);

    return true;
}

bool verify_file_is_empty(const char *name) {
    int fd = open(name, O_RDONLY);

    if (fd == -1) {
        return false;
    }

    char buf;
    int bytes_read = read(fd, &buf, 1);
    close(fd);

    return bytes_read == 0;
}

int parse_line_count(int fd) {
    char *line = NULL;
    int result = mx_read_line(&line, 1, '\n', fd);

    if (result < 0) {
        return -1;
    }

    int count = 0;
    mx_atoi(line, &count);
    mx_strdel(&line);

    return count;
}

int parse_line_data(int fd, char **vertex1, char **vertex2, int *weight) {
    int result = mx_read_line(vertex1, 1, '-', fd);

    if (result < 0) {
        return 0;
    }

    result = mx_read_line(vertex2, 1, ',', fd);

    if (result < 0) {
        mx_strdel(vertex1);

        return -1;
    }

    char *weight_str = NULL;
    result = mx_read_line(&weight_str, 1, '\n', fd);

    if (result < 0) {
        mx_strdel(vertex1);
        mx_strdel(vertex2);

        return -1;
    }

    mx_atoi(weight_str, weight);
    mx_strdel(&weight_str);

    if (!verify_vertex_name(*vertex1)
        || !verify_vertex_name(*vertex2)
        || mx_strcmp(*vertex1, *vertex2) == 0
        || *weight <= 0) {
        mx_strdel(vertex1);
        mx_strdel(vertex2);

        return -1;
    }

    return 1;
}

t_graph *parse_file(int fd) {
    int count = parse_line_count(fd);

    if (count <= 0) {
        int line = 1;
        print_error_message(LINE_IS_NOT_VALID, &line);

        return NULL;
    }

    t_graph *graph = NULL;
    graph = create_graph(count);
    int result = 0;
    result = fill_graph_data(fd, graph);

    if (result == 0
        && !verify_graph_fullness(graph)) {
        print_error_message(INVALID_NUMBER_OF_VERTICES, NULL);
        result = -1;
    }

    if (result == 0
        && calculate_sum_of_all_edges(graph) > INT_MAX) {
        print_error_message(INVALID_EDGES_SUM, NULL);
        result = -1;
    }

    if (result < 0) {
        delete_graph_data(graph);
        graph = NULL;
    }

    return graph;
}

