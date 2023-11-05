#include<bits\stdc++.h>
using namespace std;
int coinChange(int,vector<int>&);
int main(void)
{
    int x,n;
    cout<<"Enter the value:";
    cin>>x;
    vector<int>r;
    cout<<"Enter the no of denominations:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ra;
        cin>>ra;
        r.push_back(ra);
    }
    int coins=coinChange(x,r);
    cout<<coins<<endl;
    return 0;
}

int coinChange(int x,vector<int> &r)
{
    if(x==0)
    return 0;
    int n=r.size();
    int result;
    result=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(x>=r[i])
        {
            int coins=coinChange(x-r[i],r);
            if(coins!=INT_MAX && coins+1<result)
            {
                result=coins+1;
            }
        }
    }
    return result;
}