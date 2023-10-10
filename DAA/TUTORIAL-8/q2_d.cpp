#include<iostream>
using namespace std;
int check(int b,int c)
{
    for(int i=1;i<b;i++)
     {
         if(c+i==2*b&&c+i>2)
         return i;
     }
     return 0;
}
void greedy(int x,int a,int b,int c)
{
    if(a==1)
    {
     cout<<"Greedy method is applicable for given denominations"<<endl;
     int c1,c2,c3,r1,r2,k;
     c1=x/c;
     r1=x%c;
     c2=r1/b;
     r2=r1%b;
     c3=r2/1;
     k=check(b,c);
     if(k!=0&&c1>0&&c3==k)
     {
          c1=c1-1;
          c2=c2+2;
          c3=c3-k;
         cout<<"Minimum number of coins "<<c1+c2+c3<<endl;
     }
     else
     {
         cout<<"Minimum number of coins "<<c1+c2+c3<<endl;
     }
    }
    else 
    {
        cout<<"Greedy method is not applicable for given denominations"<<endl;
        return;
    }
}
int main()
{
    int x,d1,d2,d3;
    cout<<"Enter the natural number and values of denominations in ascending order "<<endl;
    cin>>x>>d1>>d2>>d3;
    greedy(x,d1,d2,d3);
}
