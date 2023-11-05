// Practice - 1 - 24/July/2023
// 2. Discover 3 different logic to swap two integers. Ensure correctness is
// guaranteed; logic must work for all inputs.

#include<stdio.h>
//Swap 2 integers, Sum, Mul, Binary shift
//T.C. O(1)
//S.C. O(1)
int main() {
	int method, x, y;
	printf("Enter any two integers:-\n");
	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	printf("Implement code in method: ");
	scanf("%d", &method);
	switch(method)
	{
	case 1:
    {
	x = x + y;
	y = x - y;
	x = x - y;
	break;
    }
	case 2:
	{
	x = x * y;
	y = x / y;
	x = x / y;
	break;
    } 
    case 3:
    {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    break;
	}
    case 4:
    {
    int temp;
	temp = x;
	x = y;
	y = temp;
	break;	
	}
	default:printf("Enter a valid method number");
	break;
    }
    printf("After swap:-\n");
	printf("x: %d\ty: %d", x, y);
}

/*Case 1:-
   1. Given two elements (x, y) are added and stored in x
   2. y is subtracted from x (total) and stored in y
   3. y (new) is again subtracted from x and stored in x
   4. Thus, elements are swapped
   
  Case 2:-
   1. Given two elements (x, y) are multiplied and stored in x
   2. x is divided by y and stored in y
   3. x is again divided by y (new) and stored in x
   4. Thus, elements are swapped
   
  Case 3:-
   1. Take exclusive or of x and y and store in x
   2. y is updated as x ^ y
   3. x is updated as x ^ y
   4. Thus, elements are swapped
   
  Case 4:-
   1. Take a temporary variable temp
   2. x is stored in temp
   3. y is stored in x
   4. temp is stored in y
   5. Thus, elements are swapped*/