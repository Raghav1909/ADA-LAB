// Write a C program to find the transitive closure using Warshall's Algorithm

#include <stdio.h>

int i, j, k, n, p[10][10];

void warshall()
{
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (p[i][k] == 1)
                for (j = 0; j < n; j++)
                    p[i][j] = p[i][j] || p[k][j];
        }
    }
}

void main()
{
    printf("Enter the no of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &p[i][j]);
    }

    warshall();

    printf("\nTransitive closure\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}