#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minProduct(vector<int>&arr){
    int cn=0, cz=0 , cp=0;   //count of zero, +ve and -ve
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0) cn++;
        if(arr[i]==0) cz++;
        if(arr[i]>0) cp++;
    }

    int result = 1;
    if(cn==0){         // -ve doesn't exist
        if(cz>0){      // 0 return
            result = 0;
        }       
        else{
            auto it = min_element(arr.begin(),arr.end());   //min +ve
            result = *it;
        }
    }
    else{               // -ve exit
        if(cn%2==0){    // even
            sort(arr.begin(),arr.end());
            for(int i=0;i<cn-1;i++){
                result *= arr[i];
            }
            for(int i=cn;i<arr.size();i++){
                result *= arr[i];
            }
        }
        else{           //odd
            for(int i=0;i<arr.size();i++){
                result *= arr[i];
            }
        }
    }

    return result;

}


int main(){
    vector<int>arr = {-2,-3,1,4,-2,-5,0};
    cout<<minProduct(arr);

    return 0;
}