class Solution {
    // {arr[row][col],{row,col}}
    typedef pair<int,pair<int,int>>p;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<p,vector<p>,greater<p>>pq;
        int maxEle = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxEle = max(maxEle,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        int minEle = pq.top().first;
        int start = minEle;
        int end = maxEle;
        
        while(true){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col==nums[row].size()-1) break;
            pq.push({nums[row][col+1],{row,col+1}});
            maxEle = max(maxEle,nums[row][col+1]);
            minEle = pq.top().first;
            if(maxEle-minEle<end-start){
                end=maxEle;
                start=minEle;
            }
        }
        return {start,end};
    }
}; 