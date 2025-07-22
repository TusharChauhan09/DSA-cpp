// 746. Min Cost Climbing Stairs     (Easy)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion 
class Solution {
public:
    int costCal(vector<int>& cost, int cur) {
        if (cur >= cost.size()) return 0; 
        int oneStep = costCal(cost, cur + 1);
        int twoStep = costCal(cost, cur + 2);
        return cost[cur] + min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(costCal(cost, 0), costCal(cost, 1));
    }
};

// Tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2;i<n;i++){
            cost[i] += min(cost[i-1],cost[i-2]); 
        }
        return min(cost[n-1],cost[n-2]);
    }
};

// Memoization 
class Solution {
public:
    int minCost(vector<int>&cost,int i,vector<int>&dp){
        if(i==0 || i==1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(minCost(cost,i-1,dp),minCost(cost,i-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
};

int main(){

    return 0;
}