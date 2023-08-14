#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> memo;
void fibo(int n)
{
    int f[n];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    for(int i = 0; i<n; i++)
    {
        cout<<"Fibo:"<<i<<"th element: "<<f[i]<<endl;
    }
}
void fibo1(int n)
{
    int a = 0;
    int b = 1;
    int c;
    cout<<"Fibo:"<<"0"<<"th element: "<<a<<endl;
    cout<<"Fibo:"<<"1"<<"th element: "<<b<<endl;
    for(int i = 0; i<n-2; i++)
    {
        c = a+b;
        cout<<"Fibo:"<<i+2<<"th element: "<<c<<endl;
        a = b;
        b = c;
    }
}
int fibo2(int n)
{
    
        if(memo.find(n)!=memo.end())
        {
            return memo[n];
        }
    
    if (n <= 1) {
        memo[n] = n;
    } else {
        memo[n] = fibo2(n - 1) + fibo2(n - 2);
        
    }
   
    return memo[n];
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the Fibonacci series:";
    cin>>n;
    fibo(n);
    cout<<"Method 2 for Fibonacci series:"<<endl;
    fibo1(n);
    cout<<"Method 3 for Fibonacci series:"<<endl;
    int c = fibo2(n);
    for(int i = 0; i<n; i++)
    {
        cout<<memo[i]<<endl;
    }
}#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> memo;
void fibo(int n)
{
    int f[n];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    for(int i = 0; i<n; i++)
    {
        cout<<"Fibo:"<<i<<"th element: "<<f[i]<<endl;
    }
}
void fibo1(int n)
{
    int a = 0;
    int b = 1;
    int c;
    cout<<"Fibo:"<<"0"<<"th element: "<<a<<endl;
    cout<<"Fibo:"<<"1"<<"th element: "<<b<<endl;
    for(int i = 0; i<n-2; i++)
    {
        c = a+b;
        cout<<"Fibo:"<<i+2<<"th element: "<<c<<endl;
        a = b;
        b = c;
    }
}
int fibo2(int n)
{
    
        if(memo.find(n)!=memo.end())
        {
            return memo[n];
        }
    
    if (n <= 1) {
        memo[n] = n;
    } else {
        memo[n] = fibo2(n - 1) + fibo2(n - 2);
        
    }
   
    return memo[n];
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the Fibonacci series:";
    cin>>n;
    fibo(n);
    cout<<"Method 2 for Fibonacci series:"<<endl;
    fibo1(n);
    cout<<"Method 3 for Fibonacci series:"<<endl;
    int c = fibo2(n);
    for(int i = 0; i<n; i++)
    {
        cout<<memo[i]<<endl;
    }
}
