#include<iostream>
using namespace std;
class MinHeap{
public:
    int arr[50];
    int index;

    MinHeap(){
        index = 1;
    }

    int top(){
        return arr[1];
    }

    void push(int n){
        //push
        arr[index]=n;
        int i= index;
        index++;
        
        // reagragment
        while(i!=1){
            int parent = i/2;
            if(arr[i]<arr[parent]) swap(arr[i],arr[parent]);
            else break;
            i = parent;
        } 
    }

    void pop(){
        //pop
        index--;
        arr[1] = arr[index];
        int i = 1;

        // re-arrangment
        while(true){
            int l = 2*i;
            int r = (2*i)+1;
            if(l>index-1) break;      // don't check for r as r>l => r>index-1;   

            if(r>index-1){            // only left child is left
                if(arr[i]>arr[l]){
                    swap(arr[i],arr[l]);
                    i=l;
                }
                break;
            }

            if(arr[l]<arr[r]){               // both left and right child exist
                if(arr[i]>arr[l]){
                    swap(arr[i],arr[l]);
                    i=l;
                }
                else{
                    break;
                }
            }
            else{
                if(arr[i]>arr[r]){
                    swap(arr[i],arr[r]);
                    i=r;
                }
                else{
                    break;
                }
            }
        }
    }

    int size(){
        return index-1;
    }

    void display(){
        for(int i=1;i<=index-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};

int main(){

    MinHeap pq;
    pq.push(10);  // push
    pq.push(20); 
    pq.push(30);
    pq.push(40);
    pq.push(45);
    pq.push(4);    // push + rearrangment 

    cout<<pq.top();  // top
    cout<<"\n";
    pq.size();     // size
    cout<<"\n";

    pq.push(7);
    cout<<pq.top();   
    cout<<"\n";
    pq.size();
    cout<<"\n";

    pq.display();

    pq.pop();   //pop
    pq.display();
    
    return 0;
}