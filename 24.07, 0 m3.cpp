#include <stdio.h>
// GCD(n1,n2,...,nk), stein's method
//T.C. O(nlog(max(a,b)))
//S.C. O(log(max(a,b)))
int gcd(int a,int b)
{
   if(a==b)
    return a;
   if(a%2==0 && b%2==0)
     return 2*gcd(a/2,b/2);
   if(a%2==0 && b%2!=0)
     return gcd(a/2,b);
   if(a%2!=0 && b%2==0)
     return gcd(a,b/2);

   if(a>b)
     return gcd((a-b)/2,b);  

    return gcd((b-a)/2,a);     
}

void main()
{
   int a[100],n;

   scanf("%d",&n);

   for(int i=0;i<n;i++)
      scanf("%d",&a[i]);

    int g=gcd(a[0],a[1]);    

    for(int i=2;i<n;i++)
    {
        if(g==1)
          break;

          g=gcd(g,a[i]);
    }  

    printf("%d",g);
   
}
