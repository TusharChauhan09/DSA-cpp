class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        vector<int> starting;
        vector<int> ending;
        
        for(auto i: intervals){
            starting.push_back(i[0]);  // start times
            ending.push_back(i[1]);    // end times
        }
        
        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        
        int roomCount = 0;
        int roomCur = 0;
        int i = 0, j = 0;
        
        while(i < starting.size() && j < ending.size()){
            if(starting[i] < ending[j]){
                roomCur++;
                roomCount = max(roomCount, roomCur);
                i++;
            } else {
                roomCur--;
                j++;
            }
        }
        
        return roomCount;
    }
};
