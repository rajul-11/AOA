#include <stdio.h>
#define V 4
#define INF 999

int main() {
    int d[V][V] = {{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    int i, j, k;

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    for (i = 0; i < V; i++)
        if (d[i][i] < 0) return printf("Negative Weight Cycle Exists!\n");

    for (i = 0; i < V; i++, printf("\n"))
        for (j = 0; j < V; j++)
            d[i][j] == INF ? printf("%5s", "INF") : printf("%5d", d[i][j]);
    return 0;
}
