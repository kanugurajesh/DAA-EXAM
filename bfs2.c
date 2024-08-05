#include <stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v)
{
    visited[v] = 1;
    printf("%d\t", v);
    while (1)
    {
        for (i = 1; i <= n; i++) // for all the vertices
        {
            if (a[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
        // if queue is empty, stop while loop
        if (f >= r)
            break;
        v = q[f++]; // deque front vertex from queue
        printf("%d\t", v);
    }
}
int main()
{
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    printf("\n Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    printf("\n The nodes which are reachable are:\n");
    bfs(v);
}
