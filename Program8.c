// Write a C program to find the transitive closure using Warshall's Algorithm

#include <stdio.h>

int i, j, k, n, p[10][10];

void warshall()
{
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (p[i][j] == 0)
                {
                    if (p[i][k] && p[k][j])
                        p[i][j] == 1;
                }
            }
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