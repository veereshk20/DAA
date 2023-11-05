#include<iostream>
using namespace std;
int main()
{
    int x,k,c;
    cout<<"Enter the natural number and value of k"<<endl;
    cin>>x>>k;
if(x>=k)
{
    c=x/k;
    if(x%k!=0)
    c=c+1;
    cout<<"Minimum number of coins "<<c;
}
else
{
    c=1;
    cout<<"Minimum number of coins "<<c;
}
