// Write a C program to sort array elements using mergesort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int *c = calloc(high + 1, sizeof(int));
    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (k = low; k <= high; k++)
        a[k] = c[k];
    free(c);
}

void mergesort(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void main()
{
    int n, k, *a;
    clock_t st, et;
    double ts;
    srand(time(0));
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    a = calloc(n, sizeof(int));
    printf("\nThe Random Numbers are:\n");
    for (k = 0; k < n; k++)
    {
        a[k] = rand() % 10000;
        printf("%d\t", a[k]);
    }

    st = clock();
    mergesort(a, 0, n - 1);
    et = clock();
    ts = (double)(et - st) / CLK_TCK;
    printf("\n\nSorted Numbers are: \n");
    for (k = 0; k < n; k++)
        printf("%d\t", a[k]);
    printf("\nTime taken = %lf", ts);
}
