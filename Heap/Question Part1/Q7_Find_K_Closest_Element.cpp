// Q7
#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int,int>p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<p>pq;
        for(auto ele: arr){
            int dist = abs(ele-x);
            pq.push({dist,ele});
            if(pq.size()>k) pq.pop();
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};