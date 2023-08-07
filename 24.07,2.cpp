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
