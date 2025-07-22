#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k,l;
    cin>>n>>k>>l;

    vector<bool>dp(1000005,0);

    //base case
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;

    for(int i=2;i<=1000000;i++){
        if(i==k || i==l) continue;
        dp[i] = ! (dp[i-1] && ((i-k>=1)? dp[i-k] : 1) && ((i-l>=1)? dp[i-l] : 1));
    }

    for(int i=0;i<n;i++){
        int coins;
        cin>>coins;
        if(dp[coins]==1){ // winning state
            cout<<"A";  // A starts first 
        }
        else{ /// lossing state
            cout<<"B";
        }
    }
    return 0;
} 
// 5 2 3 3 12 113 25714 88888 ABAAB 