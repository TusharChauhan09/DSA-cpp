#include<iostream>
using namespace std;

void HeapifyDown(int arr[],int size,int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<size&&arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size&&arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        HeapifyDown(arr,size,largest);
    }
}

void buildMaxHeap(int arr[],int size){
    for(int i=size/2+1;i>=0;i--){
        HeapifyDown(arr,size,i);
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){ 
    int arr[] = {3,4,2,1,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr,size);
    display(arr,size);
    return 0;
}