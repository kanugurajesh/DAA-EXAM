#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void QuickSort(int a[], int low, int high)
{
    if (low < high) // list has more than one element
    {
        int i, j, pivot, k, temp;
        pivot = a[low]; // choose first element in the list as pivot element
        i = low;
        j = high;
        while (i < j) // if there are elements left, to be compared with pivot element
        {
            while (a[i] <= pivot && i <= j)
                i = i + 1;
            while (a[j] > pivot)
                j = j - 1;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } // end of while
        // place element at index j , at pos low
        a[low] = a[j];
        // place pivot element in its place, at index j
        a[j] = pivot;
        // call quicksort on left sub list of pivot
        QuickSort(a, low, j - 1);
        // call quicksort on right sub list of pivot
        QuickSort(a, j + 1, high);
    }
}

void main()
{
    int n, *a, k;
    clock_t st, et;
    double ts;
    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    printf("\nThe array before sorting:\n");
    for (k = 0; k < n; k++)
    {
        a[k] = n - k;
        printf("%d\t", a[k]);
    }
    st = clock();
    QuickSort(a, 0, n - 1);
    et = clock();
    ts = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nSorted Numbers are: \n ");
    for (k = 0; k < n; k++)
        printf("%d\t", a[k]);
    printf("\nThe time taken is %e", ts);
}