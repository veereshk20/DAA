#include <stdio.h>
#include <stdlib.h>
//remove inversions
//T.C. O(nlogn)
//S.C. O(n)
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;       // Index for left subarray
    int j = mid + 1;    // Index for right subarray
    int k = left;       // Index for merged subarray
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

void removeInversions(int arr[], int n) {
    int *temp = (int*)malloc(n * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions removed: %lld\n", inversions);

    free(temp);
}

int main() {
    int arr[] = {9, 6, 4, 5, 8, 1, 2, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    removeInversions(arr, n);

    printf("Array after removing inversions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

