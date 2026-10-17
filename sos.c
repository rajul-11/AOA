#include <stdio.h>

int a[20], s[20], n, t;

void f(int i, int sum, int len) {
    int k;
    if (sum == t) {
        printf("Subset = { ");
        for (k = 0; k < len; k++) printf("%d ", s[k]);
        printf("}\n");
        return;
    }
    if (i == n || sum > t) return;
    s[len] = a[i];
    f(i + 1, sum + a[i], len + 1);
    f(i + 1, sum, len);
}

int main() {
    int i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter target: ");
    scanf("%d", &t);
    f(0, 0, 0);
    return 0;
}
