#include <stdio.h>
//(i) prime factors of n (ii) prime factorization of n (iii) all factors (iv) sum of all factors
//T.C. O(n)
//S.C. O(1)
int isPrime(int num) {                                  //O(root(n))
    if (num < 2)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    int i = 5;
    int w = 2;
    
    //refer to seives (different from this method)
    
    while (i * i <= num) {
        if (num % i == 0)
            return 0;
        i += w;
    }
    return 1;
}

void primeFactorization(int n) {                        //O(root(n)*root(n)) = O(n)
    printf("Prime factorization of %d: ", n);
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            if(isPrime(i)) {
                printf("%d ", i);
            }
            n /= i;
        }
    }
    if (n > 1 && isPrime(n)) {
        printf("%d ", n);
    }
}

void allFactorsAndSum(int n) {                          //O(root(n))
    printf("All factors of %d: ", n);
    int sum = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            printf("%d ", i);
            if(i != n / i) {
                sum += n / i;
                printf("%d ", n / i);
            }
        }
    }
    printf("\nSum of all factors = %d\n", sum);
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    primeFactorization(n);
    allFactorsAndSum(n);
    return 0;
}

/*(i)1. iteratively we check the factors of given number till root(n)
     2. if the factor is a prime, we print it
     3. if given number divided by the factor is also a prime, we print it
     4. isPrime checks from 5 to root(number), if the number has a factor it returns 0. Else we return 1.
     
  (ii)1. we check from 2 to root(number)
      2. if we find a factor, we check for prime
      3. if it is a prime, then we print it and divide the number by the prime factor
      4. after checking till root(number), we check if n(number which has been divided by the prime factors in loop) is greater
         than 1 and also a prime. If it is, then we print it
         
  (iii)1. we check from 1 to root(number)
       2. if we find a factor, we print it
       3. if the number divided by the factor is a distinct factor, then we print it
       
  (iv)1. the process is same as (iii), but here we have a sum variable, which updates the sum each time, when finding a distinct factor*/
