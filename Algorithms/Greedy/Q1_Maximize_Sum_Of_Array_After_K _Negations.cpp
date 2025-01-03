// 1005.  Maximize Sum Of Array After K Negations  (Easy)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(){
    return 0;
}

// Solution 
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto i: nums){
            q.push(i);
        }

        while(k--){
            int top = q.top();
            q.pop();
            top = (-1)*top;
            q.push(top);
        }

        int result=0;
        while(!q.empty()){
            result += q.top();
            q.pop();
        }

        return result;
    }
};