#include <stdio.h>

int cost[10][10], d[10], s[10], p[10], n;

void dij(int source, int dest)
{
    int i, j, u, v, min;

    for (i = 0; i < n; i++)
    {
        d[i] = cost[source][i];
        s[i] = 0;
        p[i] = source;
    }

    s[source] = 1;

    for (i = 0; i < n; i++)
    {
        min = 999;
        u = -1;

        for (j = 0; j < n; j++)
        {
            if (d[j] < min && s[j] == 0)
            {
                min = d[j];
                u = j;
            }
        }

        if (u == -1)
            return;

        s[u] = 1;

        if (u == dest)
            return;

        for (v = 0; v < n; v++)
        {
            if (d[u] + cost[u][v] < d[v] && s[v] == 0)
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
    }
}

void print_path(int source)
{
    int dest, i;
    for (dest = 0; dest < n; dest++)
    {
        dij(source, dest);

        if (d[dest] == 999)
            printf("\n%d is not reachable from %d", dest, source);
        else
        {
            printf("\nThe shortest path from source to every other verticies are:\n");
            i = dest;

            while (i != source)
            {
                printf("%d <- ", i);
                i = p[i];
            }

            printf("%d = %d\n", i, d[dest]);
        }
    }
}

void main()
{
    int i, j, source;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("\nEnter the source vertex: ");
    scanf("%d", &source);
    print_path(source);
}