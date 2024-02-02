#include "pathfinder.h"

t_graph *create_graph(int capacity) {
    t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
    graph->count = 0;
    graph->capacity = capacity;
    graph->vertices = (char **)malloc(sizeof(char*) * capacity);
    graph->edges = (int **)malloc(sizeof(int*) * capacity);

    for (int i = 0; i < capacity; i++) {
        graph->vertices[i] = NULL;
        graph->edges[i] = (int *)malloc(sizeof(int) * capacity);

        for (int j = 0; j < capacity; j++) {
            graph->edges[i][j] = -1;
        }
    }

    return graph;
}

int get_vertex_index(t_graph *graph, char *vertex) {
    for (int i = 0; i < graph->count; i++) {
        if (mx_strcmp(vertex, graph->vertices[i]) == 0) {
            return i;
        }
    }

    return -1;
}

bool verify_graph_fullness(t_graph *graph) {
    return graph->count == graph->capacity;
}

int create_vertex(t_graph *graph, char *vertex) {
    int index = get_vertex_index(graph, vertex);

    if (index == -1
        && !verify_graph_fullness(graph)) {
        graph->vertices[graph->count] = mx_strdup(vertex);
        graph->edges[graph->count][graph->count] = 0;
        index = graph->count;
        graph->count++;
    }

    return index;
}

bool verify_vertex_name(const char *vertex) {
    if (mx_strlen(vertex) == 0) {
        return false;
    }

    for (int i = 0; i < mx_strlen(vertex); i++) {
        if (!mx_isalpha(vertex[i])) {
            return false;
        }
    }

    return true;
}

bool create_edge(t_graph *graph, int index1, int index2, int weight) {
    if (graph->edges[index1][index2] != -1) {
        return false;
    }

    graph->edges[index1][index2] = weight;
    graph->edges[index2][index1] = weight;

    return true;
}

int fill_edge(t_graph *graph, char *vertex1, char *vertex2, int weight) {
    int index1 = create_vertex(graph, vertex1);
    int index2 = create_vertex(graph, vertex2);

    if (index1 == -1
        || index2 == -1) {
        print_error_message(INVALID_NUMBER_OF_VERTICES, NULL);

        return -1;
    }

    if (!create_edge(graph, index1, index2, weight)) {
        print_error_message(DUPLICATE_EDGES, NULL);

        return -1;
    }

    return 0;
}

int fill_graph_data(int fd, t_graph *graph) {
    int result;

    for (int i = 2;; i++) {
        char *vertex1 = NULL;
        char *vertex2 = NULL;
        int weight = 0;
        result = parse_line_data(fd, &vertex1, &vertex2, &weight);

        if (result <= 0) {
            if (result < 0) {
                print_error_message(LINE_IS_NOT_VALID, &i);
            }

            break;
        }

        result = fill_edge(graph, vertex1, vertex2, weight);
        mx_strdel(&vertex1);
        mx_strdel(&vertex2);

        if (result < 0) {
            break;
        }
    }

    return result;
}

long calculate_sum_of_all_edges(t_graph *graph) {
    long sum = 0;

    for (int i = 0; i < graph->count; i++) {
        for (int j = i + 1; j < graph->count; j++) {
            sum += graph->edges[i][j];
        }
    }

    return sum;
}

void delete_graph_data(t_graph *graph) {
    for (int i = 0; i < graph->capacity; i++) {
        mx_strdel(&graph->vertices[i]);
        free(graph->edges[i]);
    }

    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

