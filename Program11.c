#include <stdio.h>
#include <stdlib.h>

int cost[10][10], n;

int find(int node, int parent[10])
{
    while (parent[node] != node)
        node = parent[node];
    return node;
}

void union_ij(int i, int j, int parent[10])
{
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void kruskal()
{
    int count, parent[10], i, j, k, min, u, v, t[10][2], sum;
    count = 0, sum = 0, k = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count < n)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (min == 999)
            break;

        i = find(u, parent);
        j = find(v, parent);

        if (i != j)
        {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += min;
            union_ij(i, j, parent);
        }
        cost[u][v] = cost[v][u] = 999;
    }

    if (count == n - 1)
    {
        printf("\nMinimum spanning tree exists");
        printf("\nCost of MST = %d", sum);
        printf("\nSpanning tree is shown below:");

        for (k = 0; k < n - 1; k++)
            printf("\n%d->%d", t[k][0], t[k][1]);
    }

    else
        printf("\nMininum spanning tree does not exist");
}

void main()
{
    int i, j;
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] == 999;
        }
    }

    kruskal();
}