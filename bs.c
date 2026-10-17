#include <stdio.h>

/* NOT in PDF: reconstructed */
int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key)      return mid;
        else if (a[mid] < key)  low = mid + 1;
        else                    high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[100], n, i, data, pos;  /* declarations reconstructed */

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    /* From PDF: */
    scanf("%d", &data);

    pos = binarySearch(a, n, data);

    if(pos != -1)
        printf("\n\nElement found at index %d", pos);
    else
        printf("\n\nElement not found");

    return 0;
}
