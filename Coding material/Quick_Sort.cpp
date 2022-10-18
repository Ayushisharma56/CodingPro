/*
Summary: Quicksort is a very efficient sorting algorithm.It has two phases:
-the partition phase and
-the sort phase. 
Most of the work is done in the partition phase - it works out where to divide the work.
The sort phase simply sorts the two smaller problems that are generated in the partition phase. 

-----Complexity: O(n·log n)--------
*/


#include <iostream>
using namespace std;

void quicksort(int arr[], int low, int high)
{
	int pivot, i, j, temp;
	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j) 
		{
			while (arr[i] <= arr[pivot] && i <= high)
			{
				i++;
			}
			while (arr[j] > arr[pivot] && j >= low)
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;
		quicksort(arr, low, j - 1);
		quicksort(arr, j + 1, high);
	}
}

int main()
{
	int size, i;
	cout<<"Enter the number of elements: ";
	cin>>size;
	int arr[size]; 
	cout<<"Enter the elements to be sorted:\n";
	for (i = 0; i < size; i++)
	{
		cin>>arr[i];
	} 
	quicksort(arr, 0, size - 1);
	cout<<"After applying quick sort\n";
	for (i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}  
	
	return 0;
}

