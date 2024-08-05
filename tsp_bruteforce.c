#include <stdio.h>

int main()
{
    int a[5][5];
    printf("enter cost adjacency matrix of a graph with 4 vertices\n");
    
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int temp[6][5] = {{1, 2, 3, 4, 1}, {1, 2, 4, 3, 1}, {1, 3, 2, 4, 1}, {1, 3, 4, 2, 1}, {1, 4, 3, 2, 1}, {1, 4, 2, 3, 1}};
    int mincost = 100000;
    int minr = 0;
    for (int i = 0; i < 6; i++)
    {
        int cost = 0, flag = 1;
        for (int j = 0; j < 4; j++)
        { // if there is an edge between vertices
            if (a[temp[i][j]][temp[i][j + 1]] != 0)
            {
                cost = cost + a[temp[i][j]][temp[i][j + 1]];
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            if (mincost > cost)
            {
                mincost = cost;
                minr = i;
            }
        }
    }
    printf("Minimum cost path: ");
    for (int i = 0; i < 5; i++)
    {
        printf("->% d", temp[minr][i]);
    }
    printf("\nMinimum cost: %d\n", mincost);
    return 0;
}