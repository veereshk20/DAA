#include<iostream>
#include<vector>
using namespace std;
int matrixMultiplication(vector<int>&dim){
    int n=dim.size();
    vector<vector<int>>m(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        m[i][i]=0;
    }
    for(int L=2;L<n;L++){
        for(int i=1;i<n-L+1;i++){
            int j=i+L-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int cost=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
                if(cost<m[i][j]){
                    m[i][j]=cost;
                }
            }
        }
    }
    return m[1][n-1];
}

int main(void){
    int n;
    cout<<"Enter no of elements in dimension vector:";
    cin>>n;
    vector<int>dim(n);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        dim[i]=d;
    }
    int minCost=matrixMultiplication(dim);
    cout<<minCost<<endl;
    return 0;
}
