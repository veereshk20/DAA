#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n,m,flag=0;
    cin>>n>>m;
    vector<vector<int>>v(n+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x][y]=1;
        // v[y][x]=1 ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=m;i++)
    {
        if(v[i][i]!=1)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    cout<<"Not reflexive";
    else
    cout<<"Reflexive";
}
