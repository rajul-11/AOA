#include <stdio.h>
#include <limits.h>
#define V 6

int main() {
    int g[V][V] = {{0,2,0,0,0,4},{2,0,8,0,0,3},{0,8,0,6,1,0},
                   {0,0,6,0,12,0},{0,0,1,12,0,2},{4,3,0,0,2,0}};
    int key[V], par[V], in[V] = {0}, i, u, v, c, total = 0;

    for (i = 0; i < V; i++) key[i] = INT_MAX, par[i] = -1;
    key[0] = 0;

    for (c = 0; c < V; c++) {
        for (u = -1, i = 0; i < V; i++)
            if (!in[i] && (u < 0 || key[i] < key[u])) u = i;
        in[u] = 1;
        for (v = 0; v < V; v++)
            if (g[u][v] && !in[v] && g[u][v] < key[v])
                key[v] = g[u][v], par[v] = u;
    }

    printf("Edge\tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", par[i], i, g[i][par[i]]);
        total += g[i][par[i]];
    }
    printf("Total Cost = %d\n", total);
    return 0;
}
