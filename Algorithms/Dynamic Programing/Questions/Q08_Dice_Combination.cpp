#include<iostream>
#include<vector>
#include<limits.h>
#include <algorithm> 

#define mod 1000000007

using namespace std;

// rec 
long long int rec(int n){
    if(n==0) return 1;
    int sum=0;
    for(int i=1;i<=6;i++){
        if(n<i) break;
        sum = (sum + rec(n-i))%mod;
    }
    return sum ;
}
 
// memo
long long int memo(int n,vector<long long int>&dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n]; 
    int sum = 0;
    for(int i=1;i<=6;i++){
        if(n<i) break;
        sum = (sum + memo(n-i,dp))%mod;
    }
    return dp[n] = sum;
}

// tab
long long int tab(int n, vector<long long int>&dp){
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=6;j++){
            if(i<j) break;
            sum = (sum + dp[i-j])%mod;
        }
        dp[i] = sum;
    }
    return dp[n];
}

int main(){

    int n;
    cin>>n;
    
    cout << rec(n);

    cout <<"\n";

    vector<long long int>dp(n+1,-1);
    cout << memo(n,dp);

     cout <<"\n";

    vector<long long int>dp2(n+1,-1);
    cout << tab(n,dp2);

    return 0;
}