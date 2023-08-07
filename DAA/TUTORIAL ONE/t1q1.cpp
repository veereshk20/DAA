#include <stdio.h>
//(i) sum of the digits  (ii) sum of distinct digits
//T.C. max(O(log10(n)),O(log10(n)))
//S.C. O(1)
int sumOfDigits(int n) {                   //O(log10(n))
    int sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sumOfDistinctDigits(int n) {           //O(log10(n))
    int digitCount[10] = {0};
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        if (digitCount[digit] == 0) {
            sum += digit;
            digitCount[digit]++;
        }
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int digitsSum = sumOfDigits(n);
    int distinctDigitsSum = sumOfDistinctDigits(n);
    printf("Sum of digits = %d\n", digitsSum);
    printf("Sum of distinct digits = %d\n", distinctDigitsSum);
    return 0;
}

/* (i)1. sum is initialised as 0
      2. sum is updated each time iteratively with the digits of the number, from 1's position
      
   (ii)1. digitCount[10] stores the number of times a particular digit appeared in the number
       2. sum is initialised as 0
       3. sum is updated in a similar way to (i), only when digit's count is 0, it is considered to be updated in sum, to avoid repetitions*/
