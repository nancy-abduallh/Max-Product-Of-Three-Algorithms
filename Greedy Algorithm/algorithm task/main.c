#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int customMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int customMin(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int maxProductOfThree(int A[], int N, int* triplet) {
    if (N < 3) {
        printf("Array size should be at least 3\n");
        return INT_MIN;
    }

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (A[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        } else if (A[i] > max2) {
            max3 = max2;
            max2 = A[i];
        } else if (A[i] > max3) {
            max3 = A[i];
        }

        if (A[i] < min1) {
            min2 = min1;
            min1 = A[i];
        } else if (A[i] < min2) {
            min2 = A[i];
        }
    }

    int product1 = max1 * max2 * max3;
    int product2 = min1 * min2 * max1;

    if (product1 > product2) {
        triplet[0] = max1;
        triplet[1] = max2;
        triplet[2] = max3;
        return product1;
    } else {
        triplet[0] = min1;
        triplet[1] = min2;
        triplet[2] = max1;
        return product2;
    }
}

int main() {
    int N;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    if (N < 3) {
        printf("Array size should be at least 3\n");
        return 1;
    }

    int A[N];
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    int triplet[3];
    int result = maxProductOfThree(A, N, triplet);

    printf("Maximal product of any triplet in the array: %d\n", result);
    printf("These Triplets are: (%d, %d, %d)\n", triplet[0], triplet[1], triplet[2]);

    return 0;
}
