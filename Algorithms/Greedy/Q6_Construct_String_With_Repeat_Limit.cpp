class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        for(char i: s){
            mp[i]++;
        }
        priority_queue<pair<char,int>>pq;
        for(auto i: mp){
            pq.push({i.first,i.second});
        }
        string ans="";
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            if (top.second <= repeatLimit) {
                for (int i = 0; i < top.second; i++) {
                    ans += top.first;
                }
            } else {
                for (int i = 0; i < repeatLimit; i++) {
                    ans += top.first;
                }
                top.second -= repeatLimit;
                if (pq.empty()) {
                    return ans;
                } else {
                    auto stop = pq.top();
                    pq.pop();
                    ans += stop.first;
                    stop.second -= 1;
                    if (stop.second > 0) {
                        pq.push(stop);
                    }
                    if (top.second > 0) {
                        pq.push(top);
                    }
                }
            }
        }
        return ans;
    }
};

//or 
class Solution {

public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>>q;
        for(auto i: mp){
            q.push(i);
        }

        string result = "";
        while(!q.empty()){

            auto firstL = q.top();
            q.pop();
            int len = min(repeatLimit,firstL.second);
            for(int i=0;i<len;i++){
                result += firstL.first;
            }

            pair<char,int> secondL;
            if((firstL.second-len)>0){
                if(!q.empty()){
                    secondL = q.top();
                    q.pop();
                    result += secondL.first;
                }
                else{
                    return result;
                }
                
                if(secondL.second-1>0) q.push({secondL.first,secondL.second-1});
                q.push({firstL.first,firstL.second-len});
            }
        }
        return result;
    }
};