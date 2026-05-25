#include <stdio.h>

#define MAX 100

int parent[MAX], n;

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v)
{
    parent[v] = u;
}

int main()
{
    int i, j, a, b, u, v, ne = 1, min, mincost = 0;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for(i = 1; i <= n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    while(ne < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v)
        {
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            unionSet(u, v);
            ne++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
