//Greedy strategy for R1,R3 and R5
#include<iostream>
using namespace std;
int main()
{
    int x,c1,c2,c3,r1,r2;
    cout<<"enter the natural number"<<endl;
    cin>>x;
    r1=x%5;
    c1=x/5;
    r2=r1%3;
    c2=r1/3;
    c3=r2/1;
    cout<<"Minimum number of coins:"<<c1+c2+c3;
}