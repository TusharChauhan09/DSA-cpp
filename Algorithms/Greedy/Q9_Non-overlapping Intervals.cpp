// 435. Non-overlapping Intervals  (Medium)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Sort on the bases of End-time
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;

        sort(intervals.begin(),intervals.end());
        int lastEndTime = intervals[0][1];
        for(int i=1;i<n;i++){
            vector<int>cur = intervals[i];
            if(lastEndTime>cur[0]){
                count++;
                lastEndTime = min(lastEndTime,intervals[i][1]);
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }

        return count;
    }
};

// Sort on the bases of End-time
bool cmp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;

        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime = intervals[0][1];
        for(int i=1;i<n;i++){
            vector<int>cur = intervals[i];
            if(lastEndTime>cur[0]){
                count++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }

        return count;
    }
};

int main(){

    return 0;
}