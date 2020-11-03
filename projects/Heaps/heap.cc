#include <stdio.h>
#include <limits.h>
#include <iostream>

int heap[1000000], heapSize;
//Making the heap a giant array for ease, along with initializing the size

void Init(){
    heapSize=0;
    heap[0] = -INT_MAX;
}

void Insert(int element){
    heapSize++;
    std::cout<<"Inserting "<<element<<" now\n";
    heap[heapSize] = element; 
    int now = heapSize;
    while(heap[now/2]>element){     //When the parent is larger
        heap[now] = heap[now/2];    //move larger parent to where the new value was
        now /= 2;
    }
    heap[now] = element;        //put new value back in, in place of the top parent displaced
    std::cout<<heap[now]<<" "<<heapSize<<" "<<now<<" "<<"Array layout: ";
    for(int i = 1; i <= heapSize; i ++)
        std::cout<<heap[i]<<" ";
    std::cout<<"\n";
}

void print(int heapSize){
    for(int i = 1; i <= heapSize; i ++)
        std::cout<<heap[i]<<" ";
    std::cout<<"\n";
}

int DeleteMin(){
    std::cout<<"\nDeleting min value. Currently: ";
    print(heapSize);

    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for(now = 1; now*2<=heapSize;now=child){
        child = now*2;
        if(child != heapSize && heap[child+1]<heap[child]){
            child++;
        }
        if(lastElement > heap[child]){
            heap[now] = heap[child];
        }
        else{
            break;
        }
    }
    heap[now] = lastElement;

    std::cout<<"Min deleted. Now it's: ";
    print(heapSize);
    return minElement;
}


int main() {
    int number_of_elements;
    printf("Program to demonstrate Heap:\nEnter the number of elements: ");
    scanf("%d", &number_of_elements);
    int iter, element;
    Init();
    printf("Enter the elements: ");
    for (iter = 0; iter < number_of_elements; iter++) {
        scanf("%d", &element);
        Insert(element);
    }
    
    for (iter = 0; iter < number_of_elements; iter++) {
        //printf("%d ", DeleteMin());
        DeleteMin();
    }
    printf("\n");
    return 0;
}