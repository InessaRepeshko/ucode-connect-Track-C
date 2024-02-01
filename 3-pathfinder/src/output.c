#include "pathfinder.h"

void print_error_message(enum e_errors error, void *data) {
    switch (error) {
        case FILE_DOES_NOT_EXIST:
            mx_printerr("error: file ");
            mx_printerr((char*)data);
            mx_printerr(" does not exist\n");
            break;

        case FILE_IS_EMPTY:
            mx_printerr("error: file ");
            mx_printerr((char*)data);
            mx_printerr(" is empty\n");
            break;

        case LINE_IS_NOT_VALID:
            {
                char *line_str = mx_itoa(*(int*)data);
                mx_printerr("error: line ");
                mx_printerr(line_str);
                mx_printerr(" is not valid\n");
                mx_strdel(&line_str);
            }
            break;

        case INVALID_NUMBER_OF_VERTICES:
            mx_printerr("error: invalid number of islands\n");
            break;

        case DUPLICATE_EDGES:
            mx_printerr("error: duplicate bridges\n");
            break;

        case INVALID_EDGES_SUM:
            mx_printerr("error: sum of bridges lengths is too big\n");
            break;

        default:
            break;
    }
}

void print_boundary(void) {
    for (int i = 0; i < 40; i++) {
        mx_printstr("=");
    }

    mx_printstr("\n");
}

void print_route(t_graph *graph, t_list *path) {
    mx_printstr("Route: ");

    while (path != NULL) {
        t_path_vertex *vertices = (t_path_vertex *)path->data;

        if (vertices->path_weight != 0) {
            mx_printstr(" -> ");
        }

        mx_printstr(graph->vertices[vertices->index]);
        path = path->next;
    }
}

void print_distance(t_list *path) {
    mx_printstr("Distance: ");

    while (path != NULL
            && path->next != NULL) {
        t_path_vertex *vertex = (t_path_vertex *)path->data;
        t_path_vertex *next_vertex = (t_path_vertex *)path->next->data;

        if (vertex->path_weight != 0) {
            mx_printstr(" + ");
        }

        mx_printint(next_vertex->path_weight - vertex->path_weight);

        if (vertex->path_weight != 0
            && path->next->next == NULL) {
            mx_printstr(" = ");
            mx_printint(next_vertex->path_weight);
        }

        path = path->next;
    }
}

void print_path(t_graph *graph, t_list *path, int start, int end) {
    print_boundary();
    mx_printstr("Path: ");
    mx_printstr(graph->vertices[start]);
    mx_printstr(" -> ");
    mx_printstr(graph->vertices[end]);
    mx_printstr("\n");
    print_route(graph, path);
    mx_printstr("\n");
    print_distance(path);
    mx_printstr("\n");
    print_boundary();
}

void print_paths_from(t_graph *graph, int start) {
    t_path_vertex *vertices = find_shortest_path(graph, start);

    for (int end = start + 1; end < graph->count; end++) {
        t_list *paths = find_all_paths(&vertices[end]);
        t_list *current_path = paths;

        while (current_path != NULL) {
            t_list *path = (t_list*)current_path->data;
            print_path(graph, path, start, end);
            mx_clear_list(&path);
            current_path = current_path->next;
        }

        mx_clear_list(&paths);
    }

    clear_vertices(vertices, graph->count);
}

void print_all_paths(t_graph *graph) {
    for (int i = 0; i < graph->count; i++) {
        print_paths_from(graph, i);
    }
}

