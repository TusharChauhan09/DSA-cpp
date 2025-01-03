// 881. Boats to Save People (Medium)


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    return 0;
}

// Solution 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }
            else{
                count++;
                j--;
            }
        }
        return count;
    }
};
