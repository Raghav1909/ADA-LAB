#include <stdio.h>

void bfs(int a[10][10], int n, int source, int visited[10])
{
    int u, v, f = 0, r = -1, q[10];

    for (u = 0; u < n; u++)
        q[u] = 0;

    visited[source] = 1;
    q[++r] = source;

    while (f <= r)
    {
        u = q[f++];

        for (v = 1; v < n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                q[++r] = v;
                visited[v] = 1;
            }
        }
    }
}

void main()
{
    int a[10][10], q[10], visited[10], n, i, j, source;

    printf("Enter the no of nodes in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

        visited[i] = 0;
    }

    printf("Enter the source vertex: \n");
    scanf("%d", &source);
    bfs(a, n, source, visited);
    printf("The reachable nodes are:\n");
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            printf("%d is reachable\n", i);
        else
            printf("%d is not reachable\n", i);
    }
}