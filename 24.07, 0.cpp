#include<bits/stdc++.h>
using namespace std;
//Neither min nor max
//T.C. O(n)
//S.C. O(n)
int main()
{
    
    int n,j=0,count = 0;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    int arr[n];
    int arr1[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int temp = arr[0];
    arr1[j] = temp;
    j+=1;
    for(int i = 1; i<n; i++)
    {
        if(temp!=arr[i])
        {
            arr1[j] = arr[i];
            temp = arr1[j];
            j+=1;
            count+=1;
        }
        
    }
    temp = arr1[0];
    // cout<<arr1[0]<<arr1[1]<<arr1[2]<<endl;
    // cout<<temp<<endl;
    for(int i = 1; i<3; i++)
    {
        if(temp==arr1[i])
        {
            count = 0;
            // cout<<"c:"<<count<<endl;
        }
    }
    // cout<<count<<endl;
    int min,max = arr1[0];
    if(count>=2)
    {
        for(int i = 0; i<2; i++)
        {
            if(min<=arr1[i])
            {
                min = arr1[i];
            }
        }
        for(int i = 0; i<2; i++)
        {
            if(max>=arr1[i])
            {
                max = arr1[i];
            }
        }
    
    for(int i = 0; i<2; i++)
    {
        if(min!=arr1[i]&&max!=arr1[i])
        {
            int num = arr1[i];
            arr1[0] = min;
            arr1[1] = num;
            arr1[2] = max;
            break;
        }
    }
    cout<<"The number which is neither minimum nor maximum is: "<<arr1[1]<<endl;
    }
    else
    {
        cout<<"a number which is neither minimum nor maximum doesnt exist"<<endl;
    }
}
