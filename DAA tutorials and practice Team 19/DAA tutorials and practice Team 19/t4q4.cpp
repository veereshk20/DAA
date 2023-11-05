#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>> a;
    int n;
    cin>>n;
    int temp1,temp2;
    for(int i = 0; i<n; i++)
    {
        cin>>temp1>>temp2;
        a.push_back(make_pair(temp1,temp2));
    }
    set<int> b;
    for(int i = 0; i<n; i++)
    {
        b.insert(a[i].second);
    }
    if(b.size()==n)
    {
        cout<<"THe function is onto"<<endl;
    }
    else
    {
        cout<<"The fucntion is not onto"<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>> a;
    int n;
    cin>>n;
    int temp1,temp2;
    for(int i = 0; i<n; i++)
    {
        cin>>temp1>>temp2;
        a.push_back(make_pair(temp1,temp2));
    }
    set<int> b;
    for(int i = 0; i<n; i++)
    {
        b.insert(a[i].second);
    }
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>> a;
    int n;
    cin>>n;
    int temp1,temp2;
    for(int i = 0; i<n; i++)
    {
        cin>>temp1>>temp2;
        a.push_back(make_pair(temp1,temp2));
    }
    set<int> b;
    for(int i = 0; i<n; i++)
    {
        b.insert(a[i].second);
    }
    if(b.size()==n)
    {
        cout<<"THe function is onto"<<endl;
    }
    else
    {
        cout<<"The fucntion is not onto"<<endl;
    }
    return 0;
}