/* Program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 

/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

/****************************************************
* function to merge two sub-arrays
* arr - input array
* l - left index of sub-array 
* r - right index of sub-array
* m - mid-point index of each sub-array
* arr[l..m] - first sub-array
* arr[m+1..r] - second sub-array
****************************************************/
void merge(int arr[], int l, int r, int m)
{
	int i,j,k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
	/* copy sub-arrays into temp srrays */
	for(i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	
	/* merge the two sub-arrays into a single array afetr comparison */
	i = 0; j = 0; k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	/* copy the rest of the elements from the sub-array if any */
	while(i < n1)
	{
		arr[k] = L[i];
		i++; k++;
	}
	while(j < n2)
	{
		arr[k] = R[j];
		j++; k++;
	}
		
}

/****************************************************
* recursive function to execute merge sort on array 
* arr - input array
* l - left index of array 
* r - right index of array
****************************************************/
void mergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		/* find array mid-point */
		int m = (r+l)/2;
		/* call mergeSort for first half array */
		mergeSort(arr, l, m);
		/* call mergeSort for first half array */
		mergeSort(arr, m+1, r);
		
		/*merge the two halves into a sorted array */
		merge(arr, l, r, m);
	}
		
}

/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {32, 21, 34, 42, 12, 4}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Input array is %d \n" , arr_size); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 