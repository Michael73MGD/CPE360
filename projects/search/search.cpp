#include <iostream>
#include <assert.h>
#include "../util/wtime.h"
using namespace std;

void linear(int *array, int size, int val){
    int is_found =0;
    double time = wtime();
    for(int i=0;i<size;i++)
    {
        if(array[i] == val)
        {
            cout<<val<<" is at index "<<i<<"\n";
            is_found=1;
            break;
        }
    }
    time = wtime() - time;
    if(is_found == 0) cout<<val<<" is not found\n";
    cout<<"Linear search time is: "<<time<<" second(s).\n";
    return;
}

void binary(int *array, int size, int val)
{
    int begin = 0;
    int end = size;
    if(array[begin]==val)
        cout<<val<<" is at index "<<begin<<"\n";
    if(array[end]==val)
        cout<<val<<" is at index "<<end<<"\n";
    
    int is_found = 0;
    double time = wtime();
    while(begin <end-1)
    {
        int middle = (begin + end)/2;
        if(val<array[middle])
            end = middle;
        else if (val > array[middle])
            begin = middle;
        else
        {
            cout<<val<<" is at index "<<middle<<"\n";
            is_found=1;
            break;
        }
        
    }
    time = wtime() - time;
    if(is_found == 0) cout<<val<<" is not found \n";
    cout<<"Binary search time is: "<<time<<" second(s).\n";
    return;
}

int main(int args, char **argv){
    cout<<"path\n";
    assert(args >= 3);
    int array_size = atoi(argv[1]);
    int val = atoi(argv[2]);
    int *array = new int[array_size];

    for(int i=0; i<array_size;i++){
        array[i] = i;
    }
    linear(array, array_size, val);
    binary(array, array_size, val);

    delete[] array;
    
    return 1;
}