// C++ implementation of Radix Sort 
#include <iostream> 
#include <cassert>
using namespace std; 

// A utility function to get maximum value in arr[] 
int get_max(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void count_sort(int arr[], int n, int exp) 
{ 
	int output[n]; // output array 
	int i, count[10] = { 0 }; 

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++) 
		count[(arr[i] / exp) % 10]++; 

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
		count[(arr[i] / exp) % 10]--; 
	} 

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radix_sort(int arr[], int n) 
{ 
	// Find the maximum number to know number of digits 
	int m = get_max(arr, n); 

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10) 
		count_sort(arr, n, exp); 
} 

// A utility function to print an array 
void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main(int args, char **argv)
{
    std::cout<<"/path/to/exe count\n";
    assert(args>1);
    int count = atoi(argv[1]);

    int *array = new int[count];
    //int *array_select = new int[count];
    //int *array_insert = new int[count];

    for(int i = 0; i < count; i ++)
    {
        int tmp = rand()%23425345;
        array[i] = tmp;

    }

    print(array,count);
    std::cout<<"\n";
    radix_sort(array, count);
    print(array,count);
    std::cout<<"\n";
    for(int i = 0; i < count - 1; i ++)
        assert(array[i+1]>=array[i]);
    
    std::cout<<"The array is sort in ascending order!\n";
}