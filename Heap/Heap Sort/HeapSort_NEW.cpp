#include<iostream>
using namespace std;

void heapify(int arr[],int size,int index){
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
        heapify(arr,size,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void buildMaxHeap(int arr[],int size){
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
}

int main(){
    int arr[]={12,23,3,2,20,10,15,4};
    int n = 8;

    buildMaxHeap(arr,n);
    // 23 20 15 4 12 10 3 2 

    cout<<"Heapify: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    heapSort(arr,n);
    // 2 3 4 10 12 15 20 23 

    cout<<"after: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

} 