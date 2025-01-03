// Q7
#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

class Solution {
public:
    typedef pair<int,vector<int>>p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p>pq;
        for(auto i: points){
            int x2 = i[0];
            int y2 = i[1];
            int dist = pow(x2-0,2)+pow(y2-0,2);   // no need for sqrt as we can comapire normally
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};