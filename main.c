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
void dfs(int node, int depth, double distance, int start_node)
{
    visited[node] = 1;
    current_path[depth] = node;
    int i = 0;
    int is_leaf = 1;
    while(i<node_count){
        if (adj_matrix[node][i] > 0 && (!visited[i] || (i == start_node && depth > 0)))
        {
            is_leaf = 0;
            dfs(i, depth + 1, distance + adj_matrix[node][i], start_node);
        }
        i++;
    }

    if (is_leaf && distance > max_distance)
    {
        max_distance = distance;
        best_path_length = depth;
        memcpy(best_path, current_path, sizeof(int) * (depth + 1));
    }

    visited[node] = 0;
}

void check_overflow(int edge_count)
{
    if (edge_count > MAX_EDGES) {
        printf("fdin is too many\n");
        exit(1);
    }
}
void print_path()
{
    int    i = 0;
        while(i <= best_path_length){
        printf("%d\n", best_path[i]);
        i++;
    }
}
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main()
{
    memset(adj_matrix, 0, sizeof(adj_matrix));
    char buffer[256];
    int start, end;
    double distance;
    int i = 0;
    while (fgets(buffer, sizeof(buffer), stdin)) {
        sscanf(buffer, " %d , %d , %lf ", &start, &end, &distance);

        check_overflow(edge_count);

        edges[edge_count].start = start;
        edges[edge_count].end = end;
        edges[edge_count].distance = distance;
        edge_count++;

        if (start >= node_count)
            node_count = start + 1;
        if (end >= node_count)
            node_count = end + 1;
    }
    while(i<edge_count)
    {
        start = edges[i].start;
        end = edges[i].end;
        distance = edges[i].distance;
        adj_matrix[start][end] = distance;
        i++;
    }
    i = 0;
    while(i<node_count)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i, 0, 0, i);
        i++;
    }
    print_path();
    return 0;
}
