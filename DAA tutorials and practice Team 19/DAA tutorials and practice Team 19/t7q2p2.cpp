#include<iostream>
using namespace std;
int main()
{
    int n,c1,c2,c3,r1,r2;
    cout<<"Enter the number"<<endl;
    cin>>n;
    r1=n%4;
    c1=n/4;
    r2=r1%3;
    c2=r1/3;
    c3=r2/1;
    if(c1!=0 && c3==2)
    {
     c1=c1-1;
     c2=c2+2;
     c3=c3-2;
    }
    cout<<"Minimum number of coins:"<<c1+c2+c3;
}