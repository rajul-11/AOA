#include <stdio.h>

/* NOT in PDF: reconstructed */
void mm(int a[], int low, int high, int *min, int *max)
{
    int mid, min1, max1;

    if (low == high) {
        *min = *max = a[low];
        return;
    }
    if (high == low + 1) {
        if (a[low] < a[high]) { *min = a[low];  *max = a[high]; }
        else                  { *min = a[high]; *max = a[low];  }
        return;
    }

    mid = (low + high) / 2;
    mm(a, low, mid, min, max);
    mm(a, mid + 1, high, &min1, &max1);

    if (min1 < *min) *min = min1;
    if (max1 > *max) *max = max1;
}

int main()
{
    int a[100], n, i, min, max;   /* declarations reconstructed */

    printf("Enter n: ");
    scanf("%d", &n);

    /* From PDF: */
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mm(a, 0, n - 1, &min, &max);

    printf("\nMinimum Element = %d", min);
    printf("\nMaximum Element = %d", max);

    return 0;
}
