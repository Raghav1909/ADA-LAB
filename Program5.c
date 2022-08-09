// Write a C program to check whether the given graph is connected or not

#include <stdio.h>

int a[10][10], visited[10], n;
int dfs(int);

void main()
{
    int i, j, src, ans;

    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    for (j = 0; j < n; j++)
        visited[j] = 0;

    printf("Enter the source node: ");
    scanf("%d", &src);
    ans = dfs(src);

    if (ans == 1)
        printf("The graph is connected\n");

    else
        printf("The graph is not connected\n");
}

int dfs(int src)
{
    int j;
    visited[src] = 1;

    for (j = 0; j < n; j++)
    {
        if (a[src][j] == 1 && visited[j] == 0)
            dfs(j);
    }

    for (j = 0; j < n; j++)
    {
        if (visited[j] == 0)
            return 0;
    }

    return 1;
}