#include "main.h"

void check_overflow(void)
{
    if (edge_count > MAX_EDGES || node_count > MAX_NODES)
    {
        printf("fdin is too many\n");
        exit(1);
    }
}
void print_path(void)
{
    int    i = 0;
    while(i <= best_path_length)
    {
        printf("%d", best_path[i]);
        if(i != best_path_length)
            printf("\n");
        i++;
    }
}