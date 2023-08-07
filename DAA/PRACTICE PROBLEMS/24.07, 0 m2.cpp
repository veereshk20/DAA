#include <stdio.h>
//Neither min nor max
//T.C. O(n)
//S.C. O(1)
int main()
{
    int a[100],n,f=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);

    int b[3]={-1,-1,-1};
    b[0]=a[0];

    for(int i=1;i<n;i++)
    {
         for(int k=0;k<3;k++)
         {
            if(b[k]==a[i])
               break;

            if(b[k]==-1)
               {
                 if(k==2)
                   f=1;
                 b[k]=a[i];
                 break;
               }     
         }

         if(f==1)
           break;
            
    }

    int f1=0;

    if(b[2]==-1)
      {
        f1=1;
        printf("number which is neither minimum nor maximum does not exist");
      }

    if(f1==0)  
    {
       int x=b[0];
       int y=b[1];
       int z=b[2];

       if(x>y && x<z || x<y && x>z)
         printf("the number which is neither max nor min is %d",x);

       if(y>z && y<x || y<z && y>x)
         printf("the number which is neither max nor min is %d",y);  

       if(z>x && z<y || z<x && z>y)
         printf("the number which is neither max nor min is %d",z);
    }
}

/*1. a[] stores elements from user
  2. b[3] will store first 3 unique elements from a[]
  3. if b[2] remains -1, then there won't be a number which is neither min nor max
  4. else, we check for an element which is neither min nor max in b[3]*/
