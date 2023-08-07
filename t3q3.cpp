#include <stdio.h>
//return missing integer
//T.C. O(n)
//S.C. O(1)
int findMissingInteger(int arr[], int n) {
    int missing = n; 
    for(int i = 0; i < n; i++) {
        missing ^= i;                 //XOR
        missing ^= arr[i]; 
    }
    return missing;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array (distinct integers from the set S):\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int missing = findMissingInteger(arr, n);
    printf("The missing integer from the set S is: %d\n", missing);
    return 0;
}


/*missing ^= i;: This line performs an XOR operation between the missing variable and the value i. 
The purpose of this operation is to cancel out all the integers in the range 0 to n-1 that are present in the array arr. 
Since missing is initialized with n, it will have all the bits set for integers from 0 to n-1. When we XOR it with i, 
it will unset the bits that represent i. So, after this line, the missing variable will only have the bits set for the integers 
that are missing from the array.

missing ^= arr[i];: This line performs another XOR operation between the missing variable and the current element of the array arr[i]. 
The purpose of this operation is to cancel out the integers that are present in the array. If arr[i] is already present in missing, 
it will unset its bits, and if it is not present, it will set its bits. 
After this line, missing will only have the bits set for the missing integer.*/


