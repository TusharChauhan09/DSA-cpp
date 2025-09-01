// rec
// class Solution {
// public:
//     int cost(vector<int>heights,int i){
//         if(i==0) return 0;  

//         int one = abs(heights[i]-heights[i-1]) + cost(heights,i-1);

//         int two = INT_MAX; 
//         if(i-2>=0){
//             two = abs(heights[i]-heights[i-2]) + cost(heights,i-2);
//         }

//         return min(one,two); 
//     }
//     int frogJump(vector<int>& heights) {
//         int i = heights.size();
//         return cost(heights,i-1);
//     }
// };

// memo
// class Solution {
// public:
//     int cost(vector<int>heights,int i,vector<int>&dp){
//         if(i==0) return 0;  

//         if(dp[i]!=-1) return dp[i];

//         int one = abs(heights[i]-heights[i-1]) + cost(heights,i-1,dp);

//         int two = INT_MAX; 
//         if(i-2>=0){
//             two = abs(heights[i]-heights[i-2]) + cost(heights,i-2,dp);
//         }

//         return dp[i] =min(one,two); 
//     }
//     int frogJump(vector<int>& heights) {
//         int i = heights.size();
//         vector<int>dp(i+1,-1);
//         return cost(heights,i-1,dp);
//     }
// };

// tab
// class Solution {
// public:
//     int frogJump(vector<int>& heights) {
//         int i = heights.size();
//         vector<int>dp(i+1,-1);
//         dp[0] = 0;
//         dp[1] = abs(heights[0]-heights[1]);
//         for(int j=2;j<i;j++){
//             int one = abs(heights[j]-heights[j-1]) + dp[j-1];
//             int two = abs(heights[j]-heights[j-2]) + dp[j-2];
//             dp[j] = min(one,two);
//         }
//         return dp[i-1];
//     }
// };

//optimized
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int i = heights.size();
        if(i==1) return 0;  
        int a = 0;
        int b = abs(heights[0] - heights[1]);
        int c = 0;
        for (int j = 2; j < i; j++) {
            int one = abs(heights[j] - heights[j - 1]) + b;
            int two = abs(heights[j] - heights[j - 2]) + a;
            c = min(one, two);
            a = b;
            b = c;
        }
        return b;
    }
};


