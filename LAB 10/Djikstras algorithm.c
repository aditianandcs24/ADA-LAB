#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j, u, min, count;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], dist[n], visited[n];

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
        visited[i] = 0;
    }

    int start;
    printf("Enter source vertex: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(count = 1; count < n; count++)
    {
        min = INF;
        u = -1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[u] + cost[u][i] < dist[i])
                dist[i] = dist[u] + cost[u][i];
        }
    }

    printf("Shortest distances from source:\n");
    for(i = 0; i < n; i++)
        printf("%d -> %d = %d\n", start, i, dist[i]);

    return 0;
}
