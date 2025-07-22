// 198. House Robber    (Medium)

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// recursion 
class Solution {
public:
    int cal(vector<int>nums,int i){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        int robCur = nums[i] + cal(nums,i+2);
        int nrobCur = cal(nums,i+1);
        return max(robCur,nrobCur); 
     }
    int rob(vector<int>& nums) {
        return cal(nums,0);
    }
};

// Memoization
class Solution {
public:
    int cal(vector<int>nums,int i,vector<int>&dp){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i]; 
        int robCur = nums[i] + cal(nums,i+2,dp);
        int nrobCur = cal(nums,i+1,dp);
        return dp[i] = max(robCur,nrobCur); 
     }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return cal(nums,0,dp);
    }
};

// tabulation : right->left
class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            int robCur = nums[i] + dp[i+2];
            int nrobCur = dp[i+1];
            dp[i] = max(robCur,nrobCur);
        }
        return dp[0];
    }
};


// tabulation : left->right
class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int robCur = nums[i] + dp[i-2];
            int nrobCur = dp[i-1];
            dp[i] = max(robCur,nrobCur);
        }
        return dp[n-1];
    }
};

int main(){

    return 0;
}