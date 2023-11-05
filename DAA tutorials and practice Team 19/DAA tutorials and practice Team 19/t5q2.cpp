#include<bits/stdc++.h>
#include"t5q2h.h"
using namespace std;
int main()
{
	int n = 1+(rand()%5000);
	int ptr[n];
	for(int i = 0; i<n; i++)
	{
		ptr[i] = 1+rand()%5000;
	}
	quickSort(ptr,0,n-1);
	for(int k = 0; k<n; k++)
	{
		cout<<ptr[k]<<endl;
	}
}