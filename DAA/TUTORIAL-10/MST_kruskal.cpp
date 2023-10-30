#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
class Edge
{
    public:
    int source;
    int dest;
    int wt;
 bool operator<(const Edge& other) const 
 {
        return wt < other.wt;
 }
};

bool compare(Edge e1,Edge e2)
{
    // syntax to sort in increasing order
    return e1.wt<e2.wt;
}
int findparent(int v,int * parent)
{
    if(parent[v]==v)
    return v;
    else
    return findparent(parent[v],parent);
}
void kruskal(Edge* input,int n,int e)
{
    //inbuilt sort function
  sort(input,input+e);
  Edge* output=new Edge[n-1];

  int count=0;
  int i=0;
  int *parent= new int[n];
  for(int i=0;i<n;i++)
  {
    parent[i]=i;
  }

  while(count!=n-1)
  {
    Edge current=input[i];
    //chech if we can add current edge in mst
    int sourceparent=findparent(current.source,parent);
    int destparent=findparent(current.dest,parent);

    if(sourceparent!=destparent)
    {
        output[count]=current;
        count++;
        parent[sourceparent]=destparent;
    }
    i++;
  }
  for(int i=0;i<n-1;i++)
  {
    if(output[i].source<output[i].dest)
    cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].wt<<endl;
    else
    cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].wt<<endl;
  }
}

int main()
{
    int n,e;
    cout<<"Enter the number of nodes and edges"<<endl;
    cin>>n>>e;
    Edge *input= new Edge[e];
    for(int i=0;i<e;i++)
    {
        cin>>input[i].source;
        cin>>input[i].dest;
        cin>>input[i].wt;
    }
    kruskal(input,n,e);
}
