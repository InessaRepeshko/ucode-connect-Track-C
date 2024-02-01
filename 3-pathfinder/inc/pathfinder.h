#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libmx.h"

/* Graph pack */
typedef struct s_graph {
    int count;
    int capacity;
    char **vertices;
    int **edges;
}              t_graph;

t_graph *create_graph(int capacity);
int get_vertex_index(t_graph *graph, char *vertex);
bool verify_graph_fullness(t_graph *graph);
int create_vertex(t_graph *graph, char *vertex);
bool verify_vertex_name(const char *vertex);
bool create_edge(t_graph *graph, int index1, int index2, int weight);
int fill_edge(t_graph *graph, char *vertex1, char *vertex2, int weight);
int fill_graph_data(int fd, t_graph *graph);
long calculate_sum_of_all_edges(t_graph *graph);
void delete_graph_data(t_graph *graph);

/* Input and output packs */
enum e_errors {
    FILE_DOES_NOT_EXIST,
    FILE_IS_EMPTY,
    LINE_IS_NOT_VALID,
    INVALID_NUMBER_OF_VERTICES,
    DUPLICATE_EDGES,
    INVALID_EDGES_SUM,
};

/* Input pack */
bool verify_file_exists(const char *name);
bool verify_file_is_empty(const char *name);
int parse_line_count(int fd);
int parse_line_data(int fd, char **vertex1, char **vertex2, int *weight);
t_graph *parse_file(int fd);
/* Output pack */
void print_error_message(enum e_errors, void *data);
void print_boundary(void);
void print_route(t_graph *graph, t_list *path);
void print_distance(t_list *path);
void print_path(t_graph *graph, t_list *path, int start, int end);
void print_paths_from(t_graph *graph, int start);
void print_all_paths(t_graph *graph);

/* Pathfinder pack */
typedef struct s_path_vertex {
    bool visited;
    int path_weight;
    int index;
    t_list *prev_vertex;
}              t_path_vertex;

t_path_vertex *initialise_vertices(t_graph *graph, int start);
t_path_vertex *find_shortest_path(t_graph *graph, int start);
bool compare_vertices(void *vertex1, void *vertex2, void *vertex);
t_list *find_all_paths(t_path_vertex *vertex);
void clear_vertices(t_path_vertex *vertices, int count);

#endif

