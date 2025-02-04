#include<iostream>
#include<vector>
#include<limits.h>
#include <algorithm> 

#define inf INT_MAX

using namespace std;

int rec(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;

    return 1 + min({ rec(n - 1), (n % 2 == 0) ? rec(n / 2) : inf, (n % 3 == 0) ? rec(n / 3) : inf });
}   

int memo(vector<int>&dp,int n){
    if(n==1)  return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = 1 + min({ memo(dp , n - 1), (n % 2 == 0) ? memo(dp,n/2) : inf, (n % 3 == 0) ? memo(dp,n/3) : inf });
}  

int tab(int n){
    vector<int>dp(n+1,-1);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i=4;i<=n;i++){
        dp[i] = 1 + min({dp[i - 1], (i % 2 == 0) ? dp[i/2] : inf, (i % 3 == 0) ? dp[i/3] : inf });
    }
    return dp[n];
}
 
int main(){

    int n;
    cin>>n;
    int ans = rec(n);
    cout<<ans<<"\n";

    vector<int>v(n+1,-1);
    ans = memo(v,n);
    cout<<ans<<"\n";

    
    ans = tab(n);
    cout<<ans;

    return 0;
}