#include<bits/stdc++.h>
using namespace std;
//Odd ball (physical balance)
//T.C. O(n)
//S.C. O(1)
int main()
{
    float arr[27], a = 0, b = 0, c = 0, temp;
    int j,n = 27;
    cout<<"Enter the weights of the ball:";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i<n; i++)
    {
        if(i<9)
        {
            a+=arr[i];
            
        }
        else if(i<18)
        {
            b+=arr[i];
            
        }
        else
        {
            c+=arr[i];
            
        }
    }
   
    if(c>a && c>b)
    {
       
        j = 18;
    }
    else if(a>c && a>b)
    {
       
        j = 0;
    }
    else if(b>a && b>c)
    {
        
        j = 9;
    }
    n = j+9;
    int k = j;
    a=b=c = 0;
    for(int i = j; i<n; i++)
    {
        if(i<3+j)
        {
            a+=arr[i];
        }
        else if(i<6+j)
        {
            b+=arr[i];
        }
        else
        {
            c+=arr[i];
        }
    }
    
    if(c>a && c>b)
    {
        
        j = 6+k;
    }
    else if(a>c && a>b)
    {
        
        j = k;
    }
    else if(b>a && b>c)
    {
        
        j = 3+k;
    }
    n = j+3;
    float max = arr[j];
    for(int i = j;i<n; i++)
    {
        if(max<=arr[i])
        {
            max = arr[i];
            k = i;
        }
    }
    cout<<"Thus the odd ball is present at index:"<<k<<endl;
}
