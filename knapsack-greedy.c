#include <stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j;
    float u;
    u = capacity;
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if (i < n)
    {
        x[i] = (u / weight[i]);
        tp = tp + (x[i] * profit[i]);
    }
    printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);
    printf("\nMaximum profit is:- %f", tp);
}
int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;
    printf("\nEnter the no. of objects:- ");
    scanf("%d", &num);
    printf("\nEnter the weights of %d objects :-", num);
    for (i = 0; i < num; i++)
        scanf("%f", &weight[i]);
    printf("\nEnter the profits of %d objects :-", num);
    for (i = 0; i < num; i++)
        scanf("%f", &profit[i]);
    printf("\nEnter the capacityacity of knapsack:- ");
    scanf("%f", &capacity);
    for (i = 0; i < num; i++)
        ratio[i] = profit[i] / weight[i];
    // sorting profits and weights according to decreasing order of p[i]/w[i] ratio
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                temp = profit[j];
                profit[j] = profit[j + 1];
            }
        }
    }
    knapsack(num, weight, profit, capacity);
    return 0;
}
