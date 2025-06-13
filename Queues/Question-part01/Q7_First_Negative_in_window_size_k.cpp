#include<iostream>
#include<queue>
using namespace std;
vector<int> firstNeg(vector<int>arr,int k){
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0) q.push(i);
    }
    for(int i=0;i<arr.size()-k+1;i++){

        while(!q.empty() && q.front()<i) q.pop();
        if(q.size()==0 || q.front()>=i+k){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {0,-1,-2,3,4,-5,6,4,7,-8};

    vector<int>ans = firstNeg(arr,3);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}