#include "main.h"
Edge edges[MAX_EDGES];
int node_count = 0;
int edge_count = 0;
double max_distance = 0;
int best_path_length = 0;

double adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int best_path[MAX_NODES];
int current_path[MAX_NODES];

int main()
{
    scanf_fnc();
    add_matrix();
    check_overflow();
    start_dfs();
    print_path();
    return 0;
}
