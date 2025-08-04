#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

ll memo(vector<ll>& arr, int i, int j, vector<vector<ll>>& dp) {
    if (i == j) return arr[i];
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(arr[i] - memo(arr, i + 1, j, dp), arr[j] - memo(arr, i, j - 1, dp));
}

ll tab(vector<ll>&arr,int n){
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i + len - 1;
            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][ j - 1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << memo(arr, 0, n - 1, dp);
    cout<<"\n";
    cout << tab(arr,n);
    return 0;
}

// 6
// 4
// 2
// 9
// 7
// 1
// 5