#include<stdio.h>
#include<float.h>
//Identify location of infinity
//T.C. O(2logn)
//S.C. O(1)
int find_first_infinity(double arr[], int size)
 {
    int left = 1;
    int right = 2;
    int comparisons = 1;
    if (arr[left] == DBL_MAX) 
        return left;
    while (arr[right] != DBL_MAX) {          //O(logn)
        left = right;
        right *= 2;
        comparisons++;
    }
    while(left <= right)                    //O(logn)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == DBL_MAX) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        comparisons++;
    }
    return left;
}

int main() 
{
    double infinite_array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, DBL_MAX,DBL_MAX,DBL_MAX,DBL_MAX,DBL_MAX,DBL_MAX,DBL_MAX,DBL_MAX,DBL_MAX,};  
    int size = sizeof(infinite_array) / sizeof(infinite_array[0]);
    int index = find_first_infinity(infinite_array, size);
    printf("The first infinity is at index %d.\n", index);
    return 0;
}