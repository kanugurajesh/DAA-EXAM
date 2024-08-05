#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int)); // Allocate memory for temp array
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    i = low;     // index of first element in first half
    k = 0;       // index of temporary array temp
    j = mid + 1; // index of first element in second half

    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    // Copy all the remaining values from i to mid of a[] into temp[].
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k++] = a[j++];
    }

    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }

    free(temp); // Free allocated memory
}

// A function to split array into two parts.
void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high) // array is having more than one element
    {
        mid = (low + high) / 2;
        // Split the data into two halves
        MergeSort(a, low, mid);      // applying mergesort on first half
        MergeSort(a, mid + 1, high); // applying mergesort on second half
        // Merge them to get sorted elements
        Merge(a, low, mid, high);
    }
}

int main()
{
    int n, *a, k;
    clock_t st, et;
    double ts;

    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("\nThe Random Numbers are:\n");
    for (k = 0; k < n; k++)
    {
        a[k] = rand() % n + 1; // generates random numbers between 1 and n
        printf("%d\t", a[k]);
    }
    printf("\n");

    st = clock();
    MergeSort(a, 0, n - 1);
    et = clock();
    ts = (double)(et - st) / CLOCKS_PER_SEC;

    printf("\nSorted Numbers are: \n");
    for (k = 0; k < n; k++)
        printf("%d\t", a[k]);
    printf("\nThe time taken is %e sec\n", ts);

    free(a); // Free allocated memory
    return 0;
}
