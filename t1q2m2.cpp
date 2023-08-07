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
