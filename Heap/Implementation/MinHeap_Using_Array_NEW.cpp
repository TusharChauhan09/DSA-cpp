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
        int smallest = index; // largest
        int left = 2*index + 1;
        int right = 2*index + 2;

        // largest will store the index of the element which
        // is greater b/w parent , left child ,right child

        if(left<size && arr[smallest]>arr[left]){
            smallest = left;
        } 
        if(right<size && arr[smallest]>arr[right]){
            smallest = right;
        }
        
        if(smallest!=index){
            swap(arr[index],arr[smallest]);
            Heapify(smallest);
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
    MinHeap pq(10);
    pq.insert(10);  // push
    pq.insert(20); 
    pq.insert(30);
    pq.insert(40);
    pq.insert(45);
    pq.insert(4);    // push + rearrangment 

    pq.deletion();   //pop
    pq.display();


    pq.insert(100);
    pq.display();
    
    return 0;
}