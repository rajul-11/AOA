#include <stdio.h>
#define INF 999

int main() {
    int n, s, c[11][11], d[11], v[11] = {0}, i, j, u, m;
    printf("Enter vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 = no edge):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (!c[i][j] && i != j) c[i][j] = INF;
        }
    printf("Enter source: ");
    scanf("%d", &s);
    for (i = 1; i <= n; i++) d[i] = c[s][i];
    d[s] = 0; v[s] = 1;
    for (j = 1; j < n; j++) {
        for (u = s, m = INF, i = 1; i <= n; i++)
            if (!v[i] && d[i] < m) m = d[u = i];
        v[u] = 1;
        for (i = 1; i <= n; i++)
            if (!v[i] && m + c[u][i] < d[i]) d[i] = m + c[u][i];
    }
    for (i = 1; i <= n; i++)
        if (i != s) printf("%d -> %d = %d\n", s, i, d[i]);
    return 0;
}
