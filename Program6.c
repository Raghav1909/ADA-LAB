#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int p)
{
    int l, r, largest;
    l = 2 * p + 1;
    r = 2 * p + 2;

    largest = p;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != p)
    {
        swap(&a[p], &a[largest]);
        heapify(a, n, largest);
    }
}

void build_heap(int a[], int n)
{
    int p;
    for (p = n / 2 - 1; p >= 0; p--)
        heapify(a, n, p);
}

void heap_sort(int a[], int n)
{
    int i;
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        build_heap(a, i);
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
    build_heap(a, n);
    heap_sort(a, n);
    et = clock();
    ts = (double)(et - st) / CLK_TCK;
    printf("\n\nSorted Numbers are: \n");
    for (k = 0; k < n; k++)
        printf("%d\t", a[k]);
    printf("\nTime taken = %lf", ts);
}