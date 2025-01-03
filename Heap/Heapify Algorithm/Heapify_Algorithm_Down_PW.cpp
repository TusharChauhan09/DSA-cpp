#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){    // rearrangement

    while(true){
        int l = 2*i;
        int r = 2*i+1;

        if(l>=n) break;              // both doesn't exist
        if(r>=n){                    // only left exist
            if(arr[l]<arr[i]){
                swap(arr[i],arr[l]);
                i = l;
            }
            break;
        }
        if(arr[l]<arr[r]){              // both exist // l<r 
            if(arr[l]<arr[i]){
                swap(arr[l],arr[i]);
                i=l;
            }
            else break;
        }
        else{                          // r<l
            if(arr[r]<arr[i]){
                swap(arr[r],arr[i]);
                i=r;
            }
            else break;
        }
    }
}
int main(){
    int arr[] = {-1,10,2,14,11,1,4};   // starting 0 = random;
    int n = sizeof(arr)/sizeof(arr[0]);
    //before
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";


    // heapify
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    //after
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}