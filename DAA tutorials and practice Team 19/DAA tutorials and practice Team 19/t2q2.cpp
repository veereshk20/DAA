#include <stdio.h>
//Odd box (weighing machine)
//T.C. O(2n)
//S.C. O(1)
int main()
{
    int n=10;
    float b[10];
    for(int i=0;i<n;i++)         //O(n)
    {
        scanf("%f",&b[i]);
    }

    float sum=0;

    for(int i=0;i<n;i++)         //O(n)
    {
        sum=sum+(i+1)*b[i];
    }

    float sum2=(n*(n+1))/2;

    float ans=(sum-sum2)*10;

    printf("%2.f",ans);
}