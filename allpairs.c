#include <stdio.h>
#define infinity 999

int min(int, int);

void floyds(int p[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

void main()
{

    int cost[10][10], n, i, j;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix\n ");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = infinity;
        }
    }

    printf("Matrix of input data:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", cost[i][j]);
        printf("\n");
    }
    floyds(cost, n);
    printf("The costs of shortest paths are:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}