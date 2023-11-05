#include <stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void bubbleSort(int arr[],int low, int high)
{
	int size = high-low+1;
	for(int i = 0; i<size; i++)
	{
		for(int j = 0; j<size; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) 
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if(high-low+1>30)
	{
    	if (low < high)
    	{
        	int pi = partition(arr, low, high);
        	quickSort(arr, low, pi - 1);
        	quickSort(arr, pi + 1, high);
    	}
    }
    else
    
    {
    bubbleSort(arr,low,high);
    }
}