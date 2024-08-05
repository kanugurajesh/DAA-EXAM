#include <stdio.h>
int a[10][10], n, i, j, s, x[10], count = 0;

void nextvalue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
            return;
        if (a[x[k - 1]][x[k]] != 0) // is there an edge
        {
            for (j = 1; j < k; j++) // check for distinctness
                if (x[j] == x[k])
                    break;
            if (j == k) // if true, the vertex is dstinct
                if ((k < n) || (k == n) && a[x[n]][x[1]] != 0)
                    return;
        }
    } while (1); // infinite loop
}

void hamiltonian(int k)
{ // finds all hamiltonian cycles beginning at a starting vertex
    do
    {
        nextvalue(k); // assign a valid next color to vertex k
        if (x[k] == 0)
            return;
        if (k == n) // print solution
        {
            count++;
            for (i = 1; i <= n; i++)
                printf("%d-", x[i]);
            // printf("%d",s);
            printf("\n");
        }
        else
            hamiltonian(k + 1);
    } while (1);
}
void main()
{
    int i, j;
    printf("Enter No. of vertices: ");
    scanf("%d", &n);
    printf("\nEnter adjacency Matrix of graph\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("enter the starting vertex: ");
    scanf("%d", &s);
    x[1] = s;       // s is the first vertex in the cycle
    hamiltonian(2); // finds the 2nd vertex onwards in the cycle
    printf("no. of hamiltonian cycles in given graph: %d ", count);
}