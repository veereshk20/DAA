// Given a string, find the minimum number of partitions (substring) such that each partition is a palindrome.
// Sample input and output:
// ABAC =⇒ Partition-1 = ABA, Partition-2 = C. Minimum number of partitions are 2
// ABAABAAC =⇒ Partition-1 = ABAABA, Partition-2 = B, Partition-3 = C. Minimum number of partitions are 3.

#include <bits/stdc++.h>
using namespace std;

int  palin(char k[],int a,int b)
{
    int d;
    if(b==a)
      return 1;
    for(int i=0;i<(b-a+1)/2;i++)
    {
        if(k[a+i]==k[b-i])
         d=1;
        else
        {
            d=0;
            break;
		}
	}
		   return d;	
}

int main()
{
    char str[100];
    cin>>str;

    int i=0,start=0,end=strlen(str)-1;

    //cout<<palin(str,3,4)<<endl;

    while(start<=end)
    {
        if(palin(str,start,end))
        {
            //cout<<"hi"<<start<<end<<endl;
            start=end+1;
            end=strlen(str)-1;            
            i++;
        }
        else
        {
            //cout<<"bye"<<start<<end<<endl;
            end--;
        }
    }

    cout<<i<<endl;


}