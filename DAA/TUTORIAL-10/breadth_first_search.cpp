#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs_traversal(vector<vector<int>>adj,int vertices,int startVertex){
    vector<bool>visited(vertices,false);
    queue<int>q;
    visited[startVertex]=true;
    q.push(startVertex);
    cout<<startVertex<<" ";
    while(!q.empty()){
        int currVertex=q.front();
        q.pop();
        for(int i=0;i<vertices;i++){
            if(adj[currVertex][i]!= -1 && !visited[i]){
                q.push(i);
                visited[i]=true;
                cout<<i<<" ";
            }
        }
    }
}
int main(void){
    
    int v;
    cout<<"No of vertices:";
    cin>>v;
    vector<vector<int>>adj(v,vector<int>(v,-1));
    for(int i=0;i<v;i++){
        for(int j=i+1;j<v;j++){
            cout<<"Enter weight of egde between "<<i<<"and "<<j<<":";
            int d;
            cin>>d;
            adj[i][j]=d;
            adj[j][i]=adj[i][j];
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    bfs_traversal(adj,v,0);
    return 0;
}
