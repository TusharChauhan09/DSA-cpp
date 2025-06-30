class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto i: stones){
            pq.push(i);
        }

        while(pq.size()!=1){
            int first = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            pq.push(first-sec);
        }


        return pq.top();
    }
};