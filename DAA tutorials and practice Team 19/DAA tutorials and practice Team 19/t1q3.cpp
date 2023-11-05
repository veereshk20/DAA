#include <stdio.h>
//Min and second min
//T.C. O(2n - 1)
//S.C. O(n)
void findMinAndSecondMin(int a[], int size, int *min, int *secondMin) {   //(O(n + n - 1))
    for (int i = 0; i < size; i++) {
        if (a[i] < *min) {
            *secondMin = *min;
            *min = a[i];
        }
        else if (a[i] < *secondMin && a[i] != *min) {
            *secondMin = a[i];
        }
    }
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter %d elements:- \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    if(size == 0) {
    	printf("Minimum or second minimum element does not exist");
	} else if(size == 1) {
		printf("Minimum element: %d\n", a[0]);
		printf("Second minimum element does not exist");
	} else {
        int min, secondMin;
        findMinAndSecondMin(a, size, &min, &secondMin);
        printf("Minimum element: %d\n", min);
        printf("Second minimum element: %d\n", secondMin);
    }
}

/*1. we take two variables min and secondMin
  2. if a value is less than min, we update min by that element and secondMin by min
  3. we also check if any element is not less than min, but less than secondMin, then we update secondMin by that element*/