#include<bits/stdc++.h>
using namespace std;

void dfs(int a[100][100],int visited[100],int s,int n)
{
   cout<<s<<" ";

   for(int i=0;i<n;i++)
   {
      if(a[s][i]==1 && s!=i)
      {
          if(visited[i]==1)
             continue;
          else
             {
                visited[i]=1;
                dfs(a,visited,i,n);
             } 
             
      }
   }
}

int main()
{
    int n;
    int adj_mat[100][100]={0},visited[100]={0};

    cout<<"Enter the no of vertices:";
    cin>>n;

    cout<<"Enter:"<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int data;
            cin>>adj_mat[i][j];   
        }
    }

    int d;
    cout<<"Enter the node to start dfs:";
    cin>>d;

    visited[d]=1;

    dfs(adj_mat,visited,d,n);   

}