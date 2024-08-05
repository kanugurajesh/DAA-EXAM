#include <stdio.h>>
#include <math.h>>
int knapsack(float p[], float w[], float Capacity, int n)
{
    int bestChoice[20], A[20], i, k;
    float bestWeight, bestValue, tempWeight, tempValue;
    for (i = 1; i <= pow(2, n); i++)
    {
        int j = n - 1;
        float tempWeight = 0, tempValue = 0;
        // generating a bit string
        while (A[j] != 0 && j > 0)
        {
            A[j] = 0;
            j = j - 1;
        }
        A[j] = 1;
        for (k = 0; k < n; k++)
        {
            if (A[k] == 1)
            {
                tempWeight = tempWeight + w[k];
                ;
                tempValue = tempValue + p[k];
            }
        }
        if ((tempValue > bestValue) && (tempWeight <= Capacity))
        {
            bestValue = tempValue;
            bestWeight = tempWeight;
            for (k; k >= 0; k--)
                bestChoice[k] = A[k];
        }
    }
    printf("solution vector:\n{");
    for (i = 0; i < n; i++)
    {
        printf(" %d, ", bestChoice[i]);
    }
    printf("}");
    return bestValue;
}
int main()
{
    float weight[20], profit[20], capacity, bestprofit;
    int n, i, j, k;
    printf("\nEnter the no. of objects:- ");
    scanf("%d", &n);
    printf("\nEnter the weights of %d objects :-\n", n);
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);
    printf("\nEnter the profits of %d objects :-\n", n);
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);
    printf("\nEnter the capacityacity of knapsack:- ");
    scanf("%f", &capacity);
    bestprofit = knapsack(profit, weight, capacity, n);
    printf(" \nProfit : %f\n", bestprofit);
    return 0;
}