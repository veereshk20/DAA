#include <stdio.h>
//return missing integer
//T.C. O(n + 1)
//S.C. O(1)
int findMissingInteger(int arr[], int n) {
    int sum_first_n = (n * (n + 1)) / 2; 
    int sum_given_set = 0; 
    for (int i = 0; i < n; i++) {
        sum_given_set += arr[i]; 
    }
    int missing = sum_first_n - sum_given_set; 
    return missing;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array (distinct integers from the set S):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int missing = findMissingInteger(arr, n);
    printf("The missing integer from the set S is: %d\n", missing);
    return 0;
}
