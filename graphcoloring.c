#include <stdio.h>
int n, m, x[10] = {0}, a[10][10];

void Nextvalue(int k)
{
    int j;
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (j = 1; j <= n; j++)
        { // if j is adjacent to k and colors of both j and k are same
            if ((a[k][j] != 0 && x[k] == x[j]) || (a[j][k] != 0 && x[k] == x[j]))
                break;
        }
        // adjacent vertices of k have different colors from k
        // a new color found
        if (j == n + 1)
            return;
    } while (1); // infinite loop
}

void mcoloring(int k)
{
    do
    {
        Nextvalue(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            printf("{");
            for (int i = 1; i <= n; i++)
            {
                printf("%d,", x[i]);
            }
            printf("\t}\n");
        }
        else
            mcoloring(k + 1);
    } while (1);
}

int main()
{
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    printf("\n Enter graph data in matrix form:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("enter the number of colors: ");
    scanf("%d", &m);
    printf("All possible colorings of vertices of given graph:\n");
    mcoloring(1);
}
