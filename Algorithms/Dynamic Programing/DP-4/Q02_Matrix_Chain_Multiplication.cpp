#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int memo(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j || i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = INT_MAX;
    for(int k=i+1;k<j;k++){
        mini = min(mini, memo(i,k,arr,dp)+ memo(k,j,arr,dp) + arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j] = mini;
}  

int tab(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    int n = arr.size();
    for(int len=3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j = i+ len -1;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+ dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1];
} 

int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>>dp(1005,vector<int>(1005,-1));
    
    cout << memo(0,n-1,arr,dp);

    cout<<"/n";

    dp.clear();
    dp.resize(1005,vector<int>(1005,0));

    cout << tab(0,n-1,arr,dp);
    
    return 0;
}