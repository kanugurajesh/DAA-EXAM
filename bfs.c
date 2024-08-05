#include <stdio.h>

int a[10][10], queue[10], f = 0, r = 0, i, j, n, visited[10];
void BFS(int);

void main() {
    int v;
    printf("Enter no of vertices:");
    scanf("%d", &n);
    printf("\n Enter the graph in adjacency matrix form");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\n Enter starting vertex");
    scanf("%d", &v);
    printf("\n Order of visiting vertices is:%d\t", v);
    BFS(v);
}

void BFS(int v)
{
    visited[v] = 1;
    while (1)
    {
        for (i = 1; i <= n; i++)
        {
            if (a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[r++] = i;
            }
        }
        if (f > r)
            break;
        else
        {
            v = queue[f++];
            printf("%d\t", v);
        }
    }
}