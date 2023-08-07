#include<bits/stdc++.h>
using namespace std;
//GCD(n1,n2,...,nk), finding min and divide with every other
//T.C. O(2n)
//S.C. O()
int main()
{
    int min, n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 1; i<n; i++)       //O(n)
    {
        if(min<=arr[i])
        {
            min = arr[i];
        }
    }
    int rem[n];
    for(int i = 0; i<n; i++)        //O(n)
    {
        int r = arr[i]%min;
        if(r!=0)
        {
            min = min-1;
            i = 0;
        }
    }
    int gcd = min;
    cout<<"GCD is:"<<gcd<<endl;

}
