//TIME COMPLEXITY O(NLOG(N))
#include<bits/stdc++.h>
using namespace std;
void divide(int *qtr, int si, int ei);
void conquer(int *qtr, int si, int mid, int ei);
int counter = 0;
int main()
{
    int *ptr, n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    ptr = (int *) malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
    {
        cin>>ptr[i];
    }
    divide(ptr, 0, n-1);
    cout<<"COUNT"<<counter<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ptr[i]<<" ";
    }
    free(ptr);
}
void divide(int *qtr, int si, int ei)            //DIVIDING THE ARRAY RECURSIVELY UNTIL SI==EI
{
    if(si>=ei)
        return;
    
    int mid = si + (ei-si)/2; 
    divide(qtr, si, mid);
    divide(qtr,mid+1,ei);
    conquer(qtr,si,mid,ei);
}
void conquer(int *qtr, int si, int mid, int ei)         //MERGING THE ARRAYS AND SORTING THEM SIMULTANEOUSLY
{
    int s = ei-si+1;
    int arr[ei-si+1];
    int i1 = si;
    int i2 = mid+1;
    int i3 = 0;
    while(i1<=mid && i2<=ei)
    {
        if(qtr[i1]<=qtr[i2])
        {
            arr[i3++] = qtr[i1++];
            //counter+=1;
        }
        else
        {
            counter+=mid-i1+1;
            arr[i3++] = qtr[i2++];
        }
    }
    while(i1<=mid)
    {
        arr[i3++] = qtr[i1++];
        //counter+=1;
    }
    while(i2<=ei)
    {
        arr[i3++] = qtr[i2++];
        //counter+=1;
    }
    for(int i=0, j=si; i<s; i++, j++)
    {
        qtr[j] = arr[i];
    }
}
