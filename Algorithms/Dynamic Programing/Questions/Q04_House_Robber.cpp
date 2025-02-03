// 198. House Robber    (Medium)

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// iterative
class Solution {
public:
    int rec(vector<int>&nums , vector<int>&dp){
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                dp[i] = nums[i];
            }
            else if(i == n-2){
                dp[i] = max(nums[i],nums[i+1]);
            }
            else{
                dp[i] = max(dp[i+1],(nums[i] + dp[i+2]));
            }
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return rec(nums,dp);
    }
};


// Memo
class Solution {
public:
    int rec(vector<int>&nums , vector<int>&dp , int i){
        if(i == nums.size()-1){
            return nums[i];
        }
        if(i== nums.size()-2){
            return max(nums[i],nums[i+1]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max( (nums[i] + rec(nums,dp,i+2) ) , (0 + rec(nums,dp,i+1)) );
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()-1,-1);  // size = all values of i / 100
        return rec(nums,dp,0);
    }
};

// Recursive
class Solution {
public:
    int rec(vector<int>&nums , int i){
        if (i==nums.size()-1) return nums[i];
        if (i==nums.size()-2) return max(nums[i],nums[i+1]);
        return max( (nums[i] + rec(nums,i+2) ) , (0 + rec(nums,i+1)) );
    }
    int rob(vector<int>& nums) {
        return rec(nums,0);
    }
};

int main(){

    return 0;
}