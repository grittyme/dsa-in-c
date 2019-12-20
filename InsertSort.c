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

// A binary search based function to find the position 
// where item should be inserted in a[low..high] 
int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  
/* Function to sort an array a[] of size 'n' using divide and conquer approach */
void insertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        // find location where selected sould be inseretd 
        loc = binarySearch(a, selected, 0, j); 
  
        // Move all elements after location to create space 
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 

/* Function to sort an array a[] of size 'n' using Iterative approach  */
void insertSort(int arr[], int n)
{
	int i, j;
	int tmp;
	
	/* iterate from element i=1 to N-1 (last element) */
	for(i = 1; i < n; i++)
	 for(j = i; j>=1; j--)
	 {
		if (a[j]<a[j-1])
		{
		  tmp=a[j];
		  a[j]=a[j-1];
		  a[j-1]=tmp;
		}
		else
		   break;
	 }

}

/* Function to sort an array a[] of size 'n' using Recurseive approach  */
void insertionSortRecursive(int arr[], int n) 
{ 
    int j, tmp;
    // Base case 
    if (n <= 1) 
        return; 
  
    // Sort first n-1 elements 
    insertionSortRecursive( arr, n-1 ); 
	
    for(j = n-1; j>=1; j--)
    {
        if (arr[j]<arr[j-1])
        {
        	tmp=arr[j];
        	arr[j]=arr[j-1];
        	arr[j-1]=tmp;
        }
            else
                break;
    }
}



/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {32, 21, 34, 42, 12, 4}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Input array is %d \n" , arr_size); 
    printArray(arr, arr_size); 
  
    insertSort(arr, arr_size); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
