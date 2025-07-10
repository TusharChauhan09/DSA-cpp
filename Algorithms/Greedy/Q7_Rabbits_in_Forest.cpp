class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int TotalNumber = 0;
        unordered_map<int,int>mp;
        for(auto i: answers){
            int sameColor = i+1;
            if(mp.find(sameColor)==mp.end()){  // to here 
                TotalNumber += sameColor;
                if(i==0) continue;
                mp[sameColor]=1;
            }
            else{
                mp[sameColor]++;
                if(mp[sameColor]==sameColor){
                    mp.erase(sameColor);   // move from here 
                }
            }
        }
        return TotalNumber;
    }
};