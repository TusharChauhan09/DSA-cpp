#include<iostream>
#include<vector>
#include<limits.h>
#include <algorithm> 

#define inf INT_MAX

using namespace std;

vector<int> getDigits(int n){
    vector<int>digits;
    while(n>0){
        int d = n%10;
        if(d!=0){
            digits.push_back(d);
        }
        n /= 10;
    }
    return digits;
}

vector<int>dp;

// tab
int tab(int n) {
    vector<int> dp(n + 1, inf); 
    dp[0] = 0; 

    for (int i = 1; i <= n; i++) {
        vector<int> digits = getDigits(i);
        for (int d : digits) {
            if (i - d >= 0) { // Ensure valid index
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }
    return dp[n];
}

// memo
int memo(int n){
    if(n==0) return 0;
    if(n<=9) return 1;

    if(dp[n]!=-1) return dp[n];

    vector<int>digits = getDigits(n);
    int result = INT_MAX;
    for(int i=0;i<digits.size();i++){
        result = min(result, memo(n-digits[i]));
    }
    return dp[n] = 1 + result;
}

// rec
int rec(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    vector<int>digits = getDigits(n);
    int result = INT_MAX;
    for(int i=0;i<digits.size();i++){
        result = min(result, rec(n-digits[i]));
    }
    return 1 + result;
}
 
int main(){

    int n;
    cin>>n;
    
    // rec
    int ans = rec(n);
    cout<<ans<<"\n"; 

    // memo
    dp.clear();
    dp.resize(n+1,-1);
    ans = memo(n);
    cout<<ans<<"\n";

    // tab
    dp.clear();
    dp.resize(n+1,-1);
    ans = tab(n);
    cout<<ans;

    return 0;
}