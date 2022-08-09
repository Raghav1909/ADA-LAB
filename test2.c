// Write a C program to sort elements using quicksort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int count = 0;

int partition(int a[], int low, int high)
{
    int index, pivot, i;
    pivot = a[high];
    index = low;

    for (i = low; i < high; i++)
    {
        count++;
        if (a[i] <= pivot)
        {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[index], &a[high]);
    return index;
}

void quicksort(int a[], int low, int high)
{
    int index;

    if (low < high)
    {
        index = partition(a, low, high);
        quicksort(a, low, index - 1);
        quicksort(a, index + 1, high);
    }
}

void main()
{
    int n, i, k, *a;
    clock_t st, et;
    double ts;
    srand(time(0));
    // printf("Enter the number of elements to be sorted: ");
    // scanf("%d", &n);

    for (k = 10; k <= 10000; k *= 10)
    {
        count = 0;
        a = calloc(k, sizeof(int));
        for (i = 0; i < n; i++)
            a[i] = rand() % 10000;

        st = clock();
        quicksort(a, 0, k - 1);
        et = clock();
        ts = (double)(et - st) / CLK_TCK;
        printf("n = %d  count = %d\n", k, count);
        printf("Time taken = %lf\n", ts);
        free(a);
    }
    // printf("\nThe Random Numbers are:\n");
    // for (k = 0; k < n; k++)
    // {
    //     a[k] = rand() % 10000;
    //     printf("%d\t", a[k]);
    // }

    // printf("\n\nSorted Numbers are : \n");
    // for (k = 0; k < n; k++)
    //     printf("%d\t", a[k]);
}