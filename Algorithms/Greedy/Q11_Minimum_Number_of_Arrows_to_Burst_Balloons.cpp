// 452.  Minimum Number of Arrows to Burst Balloons   (Medium)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int overlap=0;
        sort(points.begin(),points.end());
        int e = points[0][1];
        for(int i=1;i<n;i++){
            if(e>=points[i][0]){
                overlap++;
                e = min(e,points[i][1]);
            }
            else{
                e = points[i][1];
            }
        }

        return n-overlap;
    }
};

int main(){

    return 0;
}