// Q6
#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include<map>
using namespace std;

// custom comapritor on priotity queue
class Solution {
public:
    typedef pair<int,int>p;
    bool static comp(const p&a, const p&b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }

        priority_queue<p,vector<p>,decltype(&comp)>pq(comp);
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        vector<int>ans;
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }

        return ans;
    }
};


/*   custom comparitor on sort funtion 
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }
            return a > b;
        });
        
        return nums;
    }
*/