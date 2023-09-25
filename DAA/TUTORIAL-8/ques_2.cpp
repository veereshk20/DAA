 //Implement COIN CHANGE - Brute Force, Greedy (if applicable), DP ; (i) R1,R3,R5 (ii) R1,R3,R4 (iii) Ra, Rb, Rc (iv) R1,R2,...,Rk

#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
    if(a<=b && b<=c)
      return a;
    else if(b<=a && b<=c)
      return b;
    else
      return c;  
}

int change(int x,int r1,int r2,int r3)
{
    if(x==0)
    return 0;
    else if(x<0)
    return INT32_MAX;
    else
    return min(change(x-r1,r1,r2,r3),change(x-r2,r1,r2,r3),change(x-r3,r1,r2,r3))+1;
}

int main()
{
    int a,b,c,x;

    cout<<"Enter the denomination(3 with spaces):";
    cin>>a>>b>>c;

    cout<<"Enter the change:";
    cin>>x;

    cout<<"Number of coins:"<<change(x,a,b,c)<<endl;

    return 0;
}
