#include <stdio.h>
#include <stdlib.h>

int n, q[20];

int solve(int r) {
    int c, i;
    if (r == n) return 1;
    for (c = 0; c < n; c++) {
        for (i = 0; i < r; i++)
            if (q[i] == c || abs(q[i] - c) == r - i) break;
        if (i == r) {
            q[r] = c;
            if (solve(r + 1)) return 1;
        }
    }
    return 0;
}

int main() {
    int i, j;
    printf("Enter N: ");
    scanf("%d", &n);
    if (n < 1 || n > 20 || !solve(0)) { printf("No solution exists for N = %d.\n", n); return 0; }
    for (i = 0; i < n; i++, printf("\n"))
        for (j = 0; j < n; j++) printf(q[i] == j ? " Q " : " . ");
    return 0;
}
