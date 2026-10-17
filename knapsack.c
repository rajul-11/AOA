#include <stdio.h>

int main() {
    int wt[] = {2, 3, 4, 5}, pr[] = {3, 4, 5, 6}, n = 4, W = 5;
    int dp[5][6] = {0}, i, w;

    for (i = 1; i <= n; i++)
        for (w = 1; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w && pr[i-1] + dp[i-1][w-wt[i-1]] > dp[i][w])
                dp[i][w] = pr[i-1] + dp[i-1][w-wt[i-1]];
        }

    printf("Maximum Profit = %d\nSelected Items: ", dp[n][W]);
    for (w = W, i = n; i > 0; i--)
        if (dp[i][w] != dp[i-1][w]) printf("Item %d ", i), w -= wt[i-1];
    printf("\n");
    return 0;
}
