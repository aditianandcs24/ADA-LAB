#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            if(i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    // Floyd's Algorithm
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    printf("Shortest path matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
