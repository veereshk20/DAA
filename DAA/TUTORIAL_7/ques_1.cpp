#include <bits/stdc++.h>
using namespace std;

int  palin(char k[],int a,int b)
{
    int d;
    if(b==a)
      return 1;
    for(int i=a;i<a+(b-a)/2;i++)
    {
        if(k[i]==k[b-i])
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
