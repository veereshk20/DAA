#include <stdio.h>
//GCD(n1,n2,....,nk), Euclidean method
//T.C. O(nlog(max(a[i],a[i - 1])))
//S.C. O(log(max(a[i],a[i - 1])))
int gcd(int a,int b)
{
   if(a>=b)
     {
        if(a%b==0)
          return b;
        else
          return gcd(b,a%b);
     }
   else
   {
        if(b%a==0)
          return a;
        else
          return gcd(a,b%a);  
   }
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
