#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void maxProductOfThreeRecursive(int A[], int N, int index, int count, int triplet[], int* maxProd, int maxTriplet[]) {
    if (count == 3) {
        int product = triplet[0] * triplet[1] * triplet[2];
        if (product > *maxProd) {
            *maxProd = product;
            for (int i = 0; i < 3; i++) {
                maxTriplet[i] = triplet[i];
            }
        }
        return;
    }

    if (index >= N) {
        return;
    }

    triplet[count] = A[index];
    maxProductOfThreeRecursive(A, N, index + 1, count + 1, triplet, maxProd, maxTriplet);

    maxProductOfThreeRecursive(A, N, index + 1, count, triplet, maxProd, maxTriplet);
}

int maxProductOfThree(int A[], int N, int maxTriplet[]) {
    if (N < 3) {
        printf("Array size should be at least 3\n");
        return INT_MIN;
    }

    int maxProd = INT_MIN;
    int tempTriplet[3];

    maxProductOfThreeRecursive(A, N, 0, 0, tempTriplet, &maxProd, maxTriplet);

    return maxProd;
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
            printf("A[%d]= ",i);
        scanf("%d", &A[i]);
    }

    int maxTriplet[3];
    int result = maxProductOfThree(A, N, maxTriplet);

    printf("Maximal product of any triplet in the array: %d\n", result);
    printf("Triplet corresponding to the maximal product: (%d, %d, %d)\n", maxTriplet[0], maxTriplet[1], maxTriplet[2]);

    return 0;
}
