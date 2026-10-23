
#include <stdio.h>

void allocate(int original[], int process[], int m, int n,
              int method, char name[]) {
    int block[20], allocation[20];
    int i, j, chosen;

    for (i = 0; i < m; i++)
        block[i] = original[i];

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        chosen = -1;

        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (chosen == -1) {
                    chosen = j;
                } else if (method == 2 &&
                           block[j] < block[chosen]) {
                    chosen = j;
                } else if (method == 3 &&
                           block[j] > block[chosen]) {
                    chosen = j;
                }
            }
        }

        if (chosen != -1) {
            allocation[i] = chosen;
            block[chosen] -= process[i];
        }
    }

    printf("\n%s\n", name);
    printf("Process\tSize\tBlock\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if (allocation[i] == -1)
            printf("Not Allocated\n");
        else
            printf("%d\n", allocation[i] + 1);
    }
}

int main() {
    int block[20], process[20];
    int m, n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    if (m < 1 || m > 20) {
        printf("Invalid number of blocks\n");
        return 1;
    }

    printf("Enter block sizes:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid number of processes\n");
        return 1;
    }

    printf("Enter process sizes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);

    allocate(block, process, m, n, 1, "First-Fit");
    allocate(block, process, m, n, 2, "Best-Fit");
    allocate(block, process, m, n, 3, "Worst-Fit");

    return 0;
}
