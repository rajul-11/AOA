#include <stdio.h>
#include <limits.h>
#define V 5
#define E 6

int main() {
    int e[E][3] = {{0,1,2},{0,2,4},{1,2,-4},{1,4,-1},{2,3,2},{4,3,-3}};
    int d[V], i, j;

    for (i = 0; i < V; i++) d[i] = INT_MAX;
    d[0] = 0;

    for (i = 1; i < V; i++)
        for (j = 0; j < E; j++)
            if (d[e[j][0]] != INT_MAX && d[e[j][0]] + e[j][2] < d[e[j][1]])
                d[e[j][1]] = d[e[j][0]] + e[j][2];

    for (j = 0; j < E; j++)
        if (d[e[j][0]] != INT_MAX && d[e[j][0]] + e[j][2] < d[e[j][1]])
            return printf("Negative Weight Cycle Exists\n");

    for (i = 0; i < V; i++) printf("Vertex %d : %d\n", i, d[i]);
    return 0;
}
