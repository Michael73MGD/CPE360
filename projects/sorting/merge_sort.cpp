#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
# include <cassert>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r]  
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1;     //size of temp arrays
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r) 
{ 
	if (l < r) { 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;        //finds the center index

		// Sort first and second halves 
		merge_sort(arr, l, m);          //recurse left side
		merge_sort(arr, m + 1, r);      //and right side

		merge(arr, l, m, r);            //by the time it gets here, recursion has sorted the left and right sides, now merge with knowledge that they are sorted
	} 
} 

/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

int main(int args, char **argv)
{
    assert(args>1);
    int count = atoi(argv[1]);  //Size of array is the only input
    int *array = new int[count];    //make array of that size
    for(int i = 0; i < count; i ++)
    {
        int tmp = rand()%100;      //fill array randomly
        array[i] = tmp;
    }

    printArray(array,count); //print before sorting
    merge_sort(array,0, count); //sort, sending the array, left, and right

    for(int i = 0; i < count - 1; i ++)     //confirm it's sorte
        assert(array[i+1]>=array[i]);
    printArray(array,count);        //print after sorting
    std::cout<<"The array is sorted in ascending order!\n";
}