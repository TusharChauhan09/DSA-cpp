//56. Merge Intervals (Medium)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Sorting On Start time  // read l->r
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()<= 1) return intervals;

        sort(intervals.begin(),intervals.end());
          
        vector<vector<int>>ans;
        vector<int>before = intervals[0];
        for(int i = 1;i<intervals.size();i++){
            vector<int>after = intervals[i];
            if(before[1]>=after[0]){
                before[1] = max(before[1],after[1]);
            }
            else{
                ans.push_back(before);
                before = after;
            }
        }
        ans.push_back(before);
        return ans;
    }
};

// Sorting On Ending time // read r->l
bool cmp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>result;
        int n = intervals.size();
        result.push_back(intervals[n-1]);

        for(int i=n-2;i>=0;i--){
            vector<int>cur = intervals[i];

            if(cur[1]>=result[result.size()-1][0]){
                result[result.size()-1][0] = min(result[result.size()-1][0],cur[0]);
                result[result.size()-1][1] = max(result[result.size()-1][1],cur[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};


int main(){

    return 0;
}