#include "pathfinder.h"

t_path_vertex *initialise_vertices(t_graph *graph, int start) {
    t_path_vertex *vertices = (t_path_vertex *)malloc(sizeof(t_path_vertex) * graph->count);

    for (int i = 0; i < graph->count; i++) {
        vertices[i].visited = false;
        vertices[i].path_weight = -1;
        vertices[i].index = i;
        vertices[i].prev_vertex = NULL;
    }

    vertices[start].path_weight = 0;

    return vertices;
}

/* Dijkstra's Shortest Path Algorithm */
t_path_vertex *find_shortest_path(t_graph *graph, int start) {
    t_path_vertex *vertices = initialise_vertices(graph, start);
    int current = start;

    while (current != -1) {
        vertices[current].visited = true;

        for (int i = 0; i < graph->count; i++) {
            int edge = graph->edges[current][i];

            if (!vertices[i].visited
                && edge != -1) {
                int path_weight = vertices[current].path_weight + edge;

                if (vertices[i].path_weight == -1
                    || path_weight <= vertices[i].path_weight) {
                    if (path_weight < vertices[i].path_weight) {
                        mx_clear_list(&vertices[i].prev_vertex);
                    }

                    vertices[i].path_weight = path_weight;
                    mx_push_back(&vertices[i].prev_vertex, &vertices[current]);
                }
            }
        }

        current = -1;

        for (int i = 0; i < graph->count; i++) {
            if (!vertices[i].visited
                && vertices[i].path_weight != -1) {
                if (current == -1
                    || vertices[i].path_weight < vertices[current].path_weight) {
                    current = i;
                }
            }
        }
    }

    return vertices;
}

/* FIFO */
bool compare_vertices(void *vertex1, void *vertex2, void *vertex) {
    if (((t_path_vertex *) vertex1)->prev_vertex == NULL 
        && (((t_path_vertex *) vertex2)->prev_vertex != NULL)) {
        while (((t_path_vertex *)((t_path_vertex *) vertex2)->prev_vertex->data)->prev_vertex) {
            vertex2 = ((t_path_vertex *) vertex2)->prev_vertex->data;
        }

        return ((t_path_vertex *) vertex)->index > ((t_path_vertex *) vertex2)->index;
    }
    
    if (((t_path_vertex *) vertex2)->prev_vertex == NULL 
        && (((t_path_vertex *) vertex1)->prev_vertex != NULL)) {
        while (((t_path_vertex *)((t_path_vertex *) vertex1)->prev_vertex->data)->prev_vertex) {
            vertex1 = ((t_path_vertex *) vertex1)->prev_vertex->data;
        }
        
        return ((t_path_vertex *) vertex)->index < ((t_path_vertex *) vertex1)->index;
    }

    return ((t_path_vertex *) vertex1)->index > ((t_path_vertex *) vertex2)->index;
}

t_list *find_all_paths(t_path_vertex *vertex) {
    if (vertex->path_weight == 0) {
        return mx_create_node(mx_create_node(vertex));
    }

    t_list *paths = NULL;
    t_list *prev_vertex = vertex->prev_vertex;
    mx_sort_list(prev_vertex, vertex, compare_vertices);

    while (prev_vertex != NULL) {
        t_list *temp = find_all_paths((t_path_vertex *)prev_vertex->data);
        t_list *current = temp;

        while (current != NULL) {
            mx_push_back((t_list**)&current->data, vertex);
            mx_push_back(&paths, current->data);
            current = current->next;
        }

        mx_clear_list(&temp);
        prev_vertex = prev_vertex->next;
    }

    return paths;
}

void clear_vertices(t_path_vertex *vertices, int count) {
    for (int i = 0; i < count; i++) {
        mx_clear_list(&vertices[i].prev_vertex);
    }

    free(vertices);
}

