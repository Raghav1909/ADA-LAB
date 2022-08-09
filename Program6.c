#include <stdio.h>

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

void print_heap(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void main()
{
    int a[5] = {4, 7, 5, 3, 6};
    int n = 5, i;
    printf("Elements before sort: ");
    print_heap(a, n);
    build_heap(a, n);
    printf("\nElements after build heap: ");
    print_heap(a, n);
    heap_sort(a, n);
    printf("\nElements after sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}