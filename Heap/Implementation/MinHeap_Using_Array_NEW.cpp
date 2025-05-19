#include<iostream>
using namespace std;
class MinHeap{
    int * arr;
    int size;        // index / size
    int total_size;   // total size
public: 
    MinHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    //insertion
    void insert(int value){
        // Check for space
        if(size==total_size){           
            cout<<"Heap Overflow\n";
            return;
        }
        // direct insertion
        arr[size] = value;
        int index = size;
        size++;

        // Heapify Up (comaprision with parent)                       
        while(index>0 && arr[index]<arr[(index-1)/2]){
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" is inserted into Heap\n";
    }

    // Heapify Down (comaprision with children)
    void Heapify(int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        // largest will store the index of the element which
        // is greater b/w parent , left child ,right child

        if(left<size && arr[largest]>arr[left]){
            largest = left;
        } 
        if(right<size && arr[largest]>arr[right]){
            largest = right;
        }
        
        if(largest!=index){
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }
        
    }

    //deletion
    void deletion(){
        //check
        if(size==0){
            cout<<"Heap Under Flow\n";
            return ;
        }
        // pop
        cout<<arr[0]<<" deleted from the heap\n";
        arr[0] = arr[size-1];
        size--;

        //Heapify Down (comparision with children)
        Heapify(0);
    }


    // display
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

};
int main(){
    int arr[] = {};
    //MaxHeap h(6);


    return 0;
}