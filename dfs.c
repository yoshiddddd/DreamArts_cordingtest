#include "main.h"

static void dfs(int node, int depth, double distance, int start_node)
{
    visited[node] = 1;
    current_path[depth] = node;
    int i = 0;
    int is_leaf = 1;
    while(i<node_count)
    {
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
void start_dfs(void)
{
    int i = 0;
    while(i<node_count)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i, 0, 0, i);
        i++;
    }

}