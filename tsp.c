#include <stdio.h>
#include <limits.h>

#define MAX 10

int a[MAX][MAX], visited[MAX], n, cost = 0, s;

int least(int c) {

    int i, nc = -1;
    int min = INT_MAX;

    for (i = 0; i < n; i++) {
        if ((a[c][i] != 0) && (visited[i] == 0) && a[c][i] < min) {
            min = a[c][i];
            nc = i;
        }
    }
    
    if (nc != -1) {
        cost += a[c][nc];
    }
    
    return nc;

}

void mincost(int city) {
    int ncity;

    visited[city] = 1;
    printf("%d --> ", city + 1); // Convert to 1-based index for output
    ncity = least(city);

    if (ncity == -1) {
        ncity = s;
        printf("%d", ncity + 1); // Convert to 1-based index for output
        cost += a[city][ncity];
        return;
    }

    mincost(ncity);
    
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("\nEnter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nThe cost matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the starting city (1 to %d): ", n);
    scanf("%d", &s);
    s--; // Convert to 0-based index

    printf("\nThe Path is:\n");
    mincost(s);
    printf("\n\nMinimum cost: %d\n", cost);

    return 0;
}
