#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition using dual pivot
void dualPivotQuickSort(int arr[], int low, int high) 
{
    if (low < high) {
        // Initialize pivot indices lp and rp
        int lp = low;
        int rp = high;

        if (arr[low] > arr[high]) 
		{
            swap(&arr[low], &arr[high]);
        }

        int pivot1 = arr[low];
        int pivot2 = arr[high];

        int i = low + 1;
        while (i <= rp)
		{
            if (arr[i] < pivot1) 
			{
                lp++;
                swap(&arr[i], &arr[lp]);
                i++;
            } 
			else if (arr[i] >= pivot2) 
			{
                while (arr[rp] >= pivot2 && i < rp)
                    rp--;
                swap(&arr[i], &arr[rp]);
                if (arr[i] < pivot1) 
				{
                    lp++;
                    swap(&arr[i], &arr[lp]);
                }
            }
            i++;
        }

        swap(&arr[low], &arr[lp]);
        swap(&arr[high], &arr[rp]);

        // Recursively sort the sub-arrays
        dualPivotQuickSort(arr, low, lp - 1);
        dualPivotQuickSort(arr, lp + 1, rp - 1);
        dualPivotQuickSort(arr, rp + 1, high);
    }
}

// Wrapper function for Dual Pivot QuickSort
void sort(int arr[], int size) 
{
    dualPivotQuickSort(arr, 0, size - 1);
}

// Function to print an array
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
	int size;
	printf("Enter the size of array");
	scanf("%d",&size);
	int arr[size];
    for(int i=0;i<size;i++)
    {
    	scanf("%d",&arr[i]);
	}
    sort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
