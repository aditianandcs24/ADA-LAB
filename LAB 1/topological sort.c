//c code for topological sorting
#include <stdio.h>

#define MAX 100

int main() {
    int n, V[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};
    int TP[MAX];
    int tp_count = 0;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &V[i][j]);
        }
    }

    // Step 1: Compute indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (V[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Main loop
    while (1) {
        int w = -1;

        // Find source vertex
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }

        // No source found
        if (w == -1)
            break;

        // Add to result
        TP[tp_count++] = w;
        visited[w] = 1;

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (V[w][i] == 1) {
                indegree[i]--;
            }
        }
    }

    // Step 3: Check cycle
    if (tp_count < n) {
        printf("Cycle detected. No topological order.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < tp_count; i++) {
            printf("%d ", TP[i]);
        }
    }

    return 0;
}
