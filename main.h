#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>

typedef struct {
    int start;
    int end;
    double distance;
} Edge;
#define MAX_NODES 1000
#define MAX_EDGES 10000
#define BUF_SIZE 256

extern Edge edges[MAX_EDGES];
extern int node_count;
extern int edge_count;
extern double max_distance;
extern int best_path_length;

extern double adj_matrix[MAX_NODES][MAX_NODES];
extern int visited[MAX_NODES];
extern int best_path[MAX_NODES];
extern int current_path[MAX_NODES];

void start_dfs(void);
void check_overflow(void);
void print_path(void);
void add_matrix(void);
void scanf_fnc(void);
#endif