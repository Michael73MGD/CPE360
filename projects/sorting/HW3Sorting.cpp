//Michael Dasaro, HW3: Bubble sort, Insertion sort, Selection sort, Merge sort, Radix sort
//Questions about time complexity are at bottom of the file
#include <cassert>
#include <iostream>
#include <math.h> 
#include <stdio.h> 
#include <string.h>
#ifndef __TIME_H__
#define __TIME_H__
#include <sys/time.h>
#include <stdlib.h>
using namespace std;
double wtime()
{
	double time[2];
	struct timeval time1;
	gettimeofday(&time1, NULL);

	time[0]=time1.tv_sec;
	time[1]=time1.tv_usec;

	return time[0]+time[1]*1.0e-6;
}
#endif

void printArr(int *arr, int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
void bubble_sort(int *arr, int n)
{
    int i;
    int j;
    for(i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
void insertion_sort(int *arr, int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) 
        { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 
void selection_sort(int *arr, int n) 
{ 
	int i, j;
    int min = 0; 
	for (i = 0; i < n-1; i++) 
	{ 
		min = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min]) 
			min = j; 
		swap(&arr[min], &arr[i]); 
	} 
} 
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
}
int get_max(int arr[], int n) 
{ 
	int max = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > max) 
			max = arr[i]; 
	return max; 
} 
void count_sort(int arr[], int n, int exp) 
{ 
	int output[n]; 
	int i, count[10] = { 0 }; 
	for (i = 0; i < n; i++) 
		count[(arr[i] / exp) % 10]++; 

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	for (i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
		count[(arr[i] / exp) % 10]--; 
	} 

	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 
void radix_sort(int arr[], int n) 
{ 
	int m = get_max(arr, n); 
	for (int exp = 1; m / exp > 0; exp *= 10) 
		count_sort(arr, n, exp); 
} 
int main(int args, char **argv)
{
    std::cout<<"/path/to/exe count\n";
    assert(args>1);
    int count = atoi(argv[1]);

    int *array_bubble = new int[count];
    int *array_select = new int[count];
    int *array_insert = new int[count];
    int *array_merge = new int[count];
    int *array_radix = new int[count];

    for(int i = 0; i < count; i ++)
    {
        int tmp = rand()%10000000;  //10 million
        array_bubble[i] = tmp;
        array_select[i] = tmp;
        array_insert[i] = tmp;
        array_merge[i] = tmp;
        array_radix[i] = tmp;
    }
    //Standard tests to confirm that the sorting is working. Test with small sizes (around 10), due to printing. 
    //Comment this section out when testing time complexity
    cout<<"Original Array: ";
    printArr(array_bubble,count);
    bubble_sort(array_bubble, count);
    cout<<"Bubble sorted: ";
    printArr(array_bubble,count);

    insertion_sort(array_insert,count);
    cout<<"Insertion sorted: ";
    printArr(array_insert,count);

    selection_sort(array_select,count);
    cout<<"Selection sorted: ";
    printArr(array_select,count);

    merge_sort(array_merge,0,count-1);
    cout<<"Merge sorted: ";
    printArr(array_merge,count);

    radix_sort(array_radix, count);
    cout<<"Radix sorted: ";
    printArr(array_radix,count);
    
    
    //Measuring time
    /*
    radix_sort(array_bubble, count);
    double time = wtime();
    insertion_sort(array_bubble, count);
    time = wtime () - time;
    cout<<time;
    */
}
/*=================================Question 1==============================
An array of size 8 million was taking unreasonably long on my computer, whereas 80,000 seems to be a good size. 
Here are the average times for each sorting algorithm in seconds:
Bubble sort:    32.4
Insertion sort: 5.9
Selection sort: 7.4
Merge sort:     0.016
Radix sort:     0.012

Radix sort is the fastest algorithm tested, though only marginally faster than merge sort. Both are orders of 
magnitude faster than the other three, with bubble sort being the slowest. This is because the array being 
sorted is extremely large, and the drastically better time complexities of merge sort and radix sort allow them 
to sort quickly, even with huge arrays. The time complexity of the three slow sorts is O(n^2), meaning that they 
take exponentially longer to finish as the array gets larger. Merge sort and radix sort on the other hand, take 
less and less extra time for each element added. For example, merge sort's time complexity is O(n*log(n)), so sorting with
80,000 numbers versus 79,999 numbers doesn't make much of a difference, while the O(n^2) algorithms are significantly affected. 

===================================Question 2===============================
For this test, I create an array similar to that above, but sort it using Radix sort first, then time an algorithm to sort it again. 
Here are the average times for each sorting algorithm in seconds:
Bubble sort:    8.8
Insertion sort: 0.001
Selection sort: 7.4
Merge sort:     0.011
Radix sort:     0.011

For this test, the array is sorted before the algorithms get to it, so they act very differently. Selection sort is by far the fastest,
taking almost no time at all (sometimes the test reports 0 as the time). This is because insertion sort only has to iterate through 
the array once, it doesn't rearrange anything because it is already sorted, and therefore doesn't take much time at all. 
Selection sort, merge sort, and radix sort don't sort much faster even though the array is sorted. This is because their worst-case 
time complexity is basically the same as their best case, or because a sorted array isn't their best case. Merge sort was actually slightly 
faster (now that it is sorted already), probably just because it was able to merge back together faster than when the array isn't sorted. 
Bubble is considerably faster than before, though still very slow. This is because it still has to go through the array with time complexity of O(n^2), 
but it is faster because it doesn't have to do any swaps along the way. 
*/