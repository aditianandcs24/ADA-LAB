#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];

    printf("Enter weight and value:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].weight, &a[i].value);
        a[i].ratio = (float)a[i].value / a[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d", &W);

    // Sort by ratio (descending)
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i].ratio < a[j].ratio)
            {
                struct Item temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    float totalValue = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(W >= a[i].weight)
        {
            W -= a[i].weight;
            totalValue += a[i].value;
        }
        else
        {
            totalValue += a[i].ratio * W;
            break;
        }
    }

    printf("Maximum value = %.2f\n", totalValue);

    return 0;
}
