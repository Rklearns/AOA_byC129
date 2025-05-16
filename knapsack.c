#include <stdio.h>

#define N 7 // number of items

int main() {
    int weight[N] = {10,20,40};
    int value[N] = {100,200,300};
    float ratio[N];
    int i, j;

    int capacity = 30;
    float totalValue = 0.0;

    // Step 1: Calculate value/weight ratio
    for (i = 0; i < N; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Step 2: Sort items in decreasing order of ratio
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap value
                int tempVal = value[i];
                value[i] = value[j];
                value[j] = tempVal;

                // Swap weight
                int tempWt = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWt;
            }
        }
    }

    // Step 3: Pick items greedily
    for (i = 0; i < N; i++) {
        if (capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
