#include <bits/stdc++.h>
using namespace std;

int sum(int a[],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
       s+=a[i];

    return s;   
}

int main()
{
    int n1,n2;
    int arr1[100],arr2[100];

    cin>>n1;

    for(int i=0;i<n1;i++)
       cin>>arr1[i];

    cin>>n2;   

    for(int j=0;j<n2;j++)
       cin>>arr2[j];

    int sum1=sum(arr1,n1);
    int sum2=sum(arr2,n2);   

    int f=0,i=0,j=0; 

    for(;i<n1;i++)
    {
        if(sum1==sum2)
          {
             cout<<"Sums are already equal.\n";
             break;
          } 

        for(j=0;j<n2;j++)
        {
            int a=0,b=0;
            a=sum1+arr2[j];
            b=sum2+arr1[i];

            if(a==b)
            {
                f=1;
                break;
            }

            
        }

        if(f==1)
          break;
    }     

    if(f==1)
      cout<<i<<" "<<j;
    else
      cout<<"no such i,j exist\n";  
}