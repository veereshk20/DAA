#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
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
    int a,b,c;
    int flag = 0;
    for(int i = 1; i<=m; i++)
    {
        
        for(int j = 1; j<=n; j++)
        {
            if(v[i][j] == 1)
            {
                for(int k = 1; k<=n; k++)
                {
                    if(v[j][k] == 1)
                    {
                        if(v[i][k] != 1)
                        {
                            // cout<<"ashrith"<<endl;
                            flag = 1;
                            break;
                        }
                        // else
                        // {
                        //      flag = 0;
                            
                        // }
                    }
                }
            }
        }
    }
    if(flag==1)
    {
        cout<<"The relation is not transitive"<<endl;
    }
    else{
        cout<<"The relation is transitive"<<endl;
    }
}
