#include <stdio.h>
//square root (x)
//T.C. O(log(x))
//S.C. O(1) 
float sqrtBinarySearch(int x) {                            //O(log(x))
    if (x == 1) 
        return x;
    float left = 1, right = x, result; 
    while (left <= right) {
        float mid = left + (right - left) / 2;
        float square = mid * mid;
        if (square == x) {
        	printf("%f", mid);
            return mid;
        } else if (square < x) {
            left = mid + 1;
            result = mid; 
        } else {
            right = mid - 1;
        }
    }
    float precision = 0.001;
    while ((result * result) < x) {                          //O(1)
        result += precision;
    }
    return result;
}

int main() {
    float x;
    printf("Enter a natural number: ");
    scanf("%f", &x);
    if (x <= 0) {
        printf("Please enter a natural number.\n");
        return 1;
    }
    float sqrt_x = sqrtBinarySearch(x);
    printf("Square root of %f is %f\n", x, sqrt_x);
}

/*1. we initialise left as 1 and right as the given number x
  2. until left <= right, using binary search method we find the closest root of the number x
  3. with a precision of 0.001, we update the result each time until it becomes greater than the number x
  4. the last passed value is returned as the result for square root of x*/ 
