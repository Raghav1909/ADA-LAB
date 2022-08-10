#include <stdio.h>

void toposort_srm(int a[10][10], int n)
{
    int indegree[10], colsum, i, j, k, u, v, top, s[10], T[10];

    for (j = 0; j < n; j++)
    {
        colsum = 0;

        for (i = 0; i < n; i++)
            colsum += a[i][j];
        indegree[j] = colsum;
    }

    top = -1;

    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            s[++top] = i;
    }

    k = 0;
    while (top != -1)
    {
        u = s[top--];
        T[k++] = u;

        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1)
            {
                indegree[v]--;

                if (indegree[v] == 0)
                    s[++top] = v;
            }
        }
    }
    printf("\nThe topological order for given graph is:\n");
    for (k = 0; k < n; k++)
        printf("%d\t", T[k]);
}

void main()
{
    int a[10][10], n, i, j;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    toposort_srm(a, n);
}