#include<stdio.h>
//(i) GCD(m,n), Euclidean method 
//T.C. O(min(x,y))  
//S.C. O(1)
int main() {
	int x, y;
    printf("Enter any two integers:-\n");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    if(x == y) {                     //O(1)
    	printf("GCD is %d", x);
	} else if(x == 0 || y == 0) {    //O(1)
		printf("GCD is 0");
	} else if(x > y) {               //O(min(x,y))
		int r = y;
		do {
			y = r;
			r = x % y;
			x = x / y;
		} while(r != 0);
		printf("GCD is %d", y);
	} else {                         //O(min(x,y))
		int r = x;
		do {
			x = r;
			r = y % x;
			y = y / x;
		} while(r != 0);
		printf("GCD is %d", x);
	}
	return 1;
}

/*In the worst case, the loop will run approximately 'y' times, 
because 'r' becomes 0 when 'y' divides 'x' completely. So, the number of iterations is roughly proportional to 'y'.*/
