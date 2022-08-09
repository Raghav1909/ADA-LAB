// Write a C program to find the shortest path by implementing Floyd's algorithm

#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd(int p[10][10], int n)
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
        }
    }
}

void main()
{
    int n, i, j, p[10][10];
    printf("Enter the no of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &p[i][j]);
    }

    floyd(p, n);

    printf("\nSolution to all pair shortest path problem is\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}