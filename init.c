#include "main.h"

void scanf_fnc(void)
{
    char buffer[BUF_SIZE];
        int start = 0, end = 0;
    double distance = 0;
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if(sscanf(buffer, " %d , %d , %lf ", &start, &end, &distance)!=3)
        {
            printf("Invalid input\n");
            exit(1);
        }
        check_overflow();
        edges[edge_count].start = start;
        edges[edge_count].end = end;
        edges[edge_count].distance = distance;
        edge_count++;
        if (start >= node_count)
            node_count = start + 1;
        if (end >= node_count)
            node_count = end + 1;
    }

}

void add_matrix(void)
{
    int i = 0;
    int start = 0, end = 0;
    double distance = 0;
    memset(adj_matrix, 0, sizeof(adj_matrix));

    while(i<edge_count)
    {
        start = edges[i].start;
        end = edges[i].end;
        distance = edges[i].distance;
        adj_matrix[start][end] = distance;
        i++;
    }

}