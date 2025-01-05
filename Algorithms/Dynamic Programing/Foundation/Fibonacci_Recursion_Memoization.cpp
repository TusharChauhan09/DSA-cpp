#include<vector>
#include<iostream>
using namespace std;

int dp_fibo(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n] = dp_fibo(n-1,dp) + dp_fibo(n-2,dp);
    return dp[n];
}
int fibo(int n){
    vector<int>dp(n+1,-1);
    return dp_fibo(n,dp);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<fibo(n);
}