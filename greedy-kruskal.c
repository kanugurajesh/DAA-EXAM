#include <stdio.h>
#define infinity 999

int a[20][20];
int p[20];
int ne = 1;
void Union(int, int);
int find(int);
int mincost = 0, cmin = infinity;

int main()
{
    int n, i, j, v1, v2, u, v;

    printf("enter number of vertices:");
    scanf("%d", &n);
    printf("enter adjacency matrix:\n");

    for (i = 1; i <= n; i++)
    {
        p[i] = -1;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = infinity;
        }
    }

    printf("\nEdges in the Minimum cost spanning tree\n");
    while (ne < n)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] < cmin)
                {
                    v1 = i;
                    v2 = j;
                    cmin = a[i][j];
                }
            }
        }
        u = find(v1);
        v = find(v2);
        if (u != v)
        {
            Union(u, v);
            mincost = mincost + a[v1][v2];
            printf("(%d,%d) = %d\n", v1, v2, a[v1][v2]);
            ne++;
        }
        cmin = infinity;
        a[v1][v2] = infinity;
        a[v2][v1] = infinity;
    }
    printf("mincost=%d", mincost);
}
void Union(int m, int n)
{
    p[m] = n;
}
int find(int i)
{
    while (p[i] != -1)
    {
        i = p[i];
    }
    return i;
}