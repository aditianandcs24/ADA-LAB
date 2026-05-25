#include <stdio.h>

int main() {
    int n, i, j, mobile, mobilePos, temp;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    // Initialize numbers and directions
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = -1;   // -1 = left, 1 = right
    }

    while (1) {

        // Print permutation
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        // Find largest mobile element
        mobile = 0;
        mobilePos = -1;

        for (i = 0; i < n; i++) {
            int next = i + dir[i];

            if (next >= 0 && next < n && a[i] > a[next]) {
                if (a[i] > mobile) {
                    mobile = a[i];
                    mobilePos = i;
                }
            }
        }

        // Stop if no mobile element
        if (mobile == 0)
            break;

        int nextPos = mobilePos + dir[mobilePos];

        // Swap numbers
        temp = a[mobilePos];
        a[mobilePos] = a[nextPos];
        a[nextPos] = temp;

        // Swap directions
        temp = dir[mobilePos];
        dir[mobilePos] = dir[nextPos];
        dir[nextPos] = temp;

        mobilePos = nextPos;

        // Reverse direction of larger elements
        for (i = 0; i < n; i++) {
            if (a[i] > mobile)
                dir[i] = -dir[i];
        }
    }

    return 0;
}
