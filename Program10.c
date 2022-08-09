#include <stdio.h>

void prims(int n, int cost[10][10])
{
    int i, j, u, v, min, sum, k, t[10][2], p[10], d[10], s[10], source;
    min = 999;
    source = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] <= min)
            {
                min = cost[i][j];
                source = i;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        d[i] = cost[source][i];
        s[i] = 0;
        p[i] = source;
    }
    s[source] = 1;
    sum = 0;
    k = 0;
    for (i = 1; i < n; i++)
    {
        min = 999;
        u = -1;
        for (j = 0; j < n; j++)
        {
            if (s[j] == 0)
            {
                if (d[j] <= min)
                {
                    min = d[j];
                    u = j;
                }
            }
        }
        t[k][0] = u;
        t[k][1] = p[u];
        k++;
        sum += cost[u][p[u]];
        s[u] = 1;
        for (v = 0; v < n; v++)
        {
            if (s[v] == 0 && cost[u][v] < d[v])
            {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }
    if (sum >= 999)
        printf("Spanning tree does not exist:\n");
    else
    {
        printf("\nSpanning tree exists and the minimum spanning tree is:\n");
        for (i = 0; i < n - 1; i++)
            printf("%d->%d\n", t[i][0], t[i][1]);

        printf("\nThe cost of the spanning tree= %d\n", sum);
    }
}
void read_matrix(int n, int a[][10])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void main()
{
    int n, cost[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    read_matrix(n, cost);
    prims(n, cost);
}