#include<iostream>
#include<vector>
#include<limits.h>
#include <algorithm> 

#define inf INT_MAX

using namespace std;

// memo 
int memo(int x, vector<int>coins,vector<int>&dp){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];
    int result = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i]<0) continue;
        result = min(result,memo(x-coins[i],coins,dp));
    } 
    if(result == INT_MAX) return dp[x]=INT_MAX;  // CAN'T BE solved therefore inf steps
    return dp[x] = 1 + result;
}
 
int main(){

    // vector<int>coins = {1,5,7};   
    // int amount = 11;
    // vector<int> dp(amount + 1, -2);

    vector<int>coins = {3,6};   
    int amount = 10;
    vector<int> dp(amount + 1, -2); 

    int ans = memo(amount,coins,dp);
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
    
    return 0;
}