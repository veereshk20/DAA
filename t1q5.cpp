#include <stdio.h>
//Min. no.of people for 3 mutual friends and 3 mutual enemies
//T.C. O(MF + ME)
//S.C. O(1)
int fact(int n)
{
    int fact=1;
    while(n>0)
    {
        fact *= n;
        n--;
    }

    return fact;
}

int ramsay_number(int s, int t)
{

    // printf("%d\n",fact(s+t-2));
    // printf("%d\n",fact(s-1));
    return fact(s+t-2)/(fact(s-1)*fact(t-1));
}

int main()
{
    int MF=3, ME=3;

    int r = ramsay_number(MF, ME);
    printf("No of people in group %d", r);
}
