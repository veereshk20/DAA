#include <bits/stdc++.h>
using namespace std;

int min(vector<int> a)
{
    int min=INT32_MAX;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]<min)
          min=a[i];
    }
    
    return min;
}

int change(int x,vector<int> r)
{
    if(x==0)
    return 0;
    else if(x<0)
    return INT32_MAX;
    else
    {
        vector<int> a;
        for(int i=0;i<r.size();i++)
        {
            a.push_back(change(x-r[i],r));
        }

        return min(a)+1;
    }
}

int main()
{
    int n,x;
    vector<int> a;

    cout<<"Enter the number of denomination:";
    cin>>n;

    cout<<"Enter the denomination(with spaces):";
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        a.push_back(y);
    }

    cout<<"Enter the change:";
    cin>>x;

    int c=change(x,a);
    cout<<"Number of Coins:";
    if(c==INT32_MAX || c<0)
       cout<<"No change exist."<<endl;
    else
       cout<<c<<endl;   

    

    return 0;
}
