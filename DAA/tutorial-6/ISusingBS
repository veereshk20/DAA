#include <stdio.h>

int binarySearch(int a[],int start,int end,int key)
{
    int mid = (start+end)/2;
 
    if(key>=a[mid])
      {
         if(key<a[mid+1])
            {
                if(mid+1>end)
                   return mid;
                else
                   return mid+1;  
            }       
         else
            return binarySearch(a,mid+1,end,key);
      }
    else
      {
        if(mid-1<0)
          return mid;
        else  
          return binarySearch(a,start,mid-1,key);
      }    
    
}

void main()
{
    int arr[100],n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
       scanf("%d",&arr[i]);

    int key,i,j,k;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        k=binarySearch(arr,0,j,key);
        while(j>=k)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[k]=key;
    }   

    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
}



