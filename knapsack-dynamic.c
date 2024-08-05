// Knapsack using Dynamic Programming tabular method
#include <stdio.h>
int w[10], p[10], n, i, j, cap, x[10] = {0};
int max(int i, int j)
{
    return ((i > j) ? i : j);
}
int main()
{
    int profit, count = 0, value;
    printf("\nEnter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the profit and weights of the elements in increasing order of weights\n");
    for (i = 1; i <= n; i++)
    {
        printf("For item no %d\n", i);
        scanf("%d%d", &p[i], &w[i]);
    }
    printf("\nEnter the capacity \n");
    scanf("%d", &cap);
    int knap[n + 1][cap + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= cap; j++)
        {
            if ((i == 0) || (j == 0))
                knap[i][j] = 0;
            else
            {
                if (j < w[i])
                    value = knap[i - 1][j];
                else
                    value = max(knap[i - 1][j], p[i] + knap[i - 1][j - w[i]]);
                knap[i][j] = value;
            }
        }
    }
    profit = knap[n][cap];
    i = n;
    j = cap;
    while (j != 0 && i != 0)
    {
        if (knap[i][j] != knap[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
            i--;
        }
        else
            i--;
    }
    printf("Solution is: ");
    for (i = 1; i <= n; i++)
        printf("%d\t", x[i]);
    printf("\n Items included are\n");
    printf("Item no\tweight\tprofit\n");
    for (i = 1; i <= n; i++)
        if (x[i])
            printf("%d\t%d\t%d\n", i, w[i], p[i]);
    printf("Total profit = %d\n", profit);
}
