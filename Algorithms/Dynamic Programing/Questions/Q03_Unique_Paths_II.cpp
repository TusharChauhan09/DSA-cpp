// 63. Unique Paths II     (Medium)

// 62. Unique Paths      (Medium)

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) obstacleGrid[i][j] = 10000;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) obstacleGrid[0][0]=1;
                else if(obstacleGrid[i][j] == 10000) continue;
                else{
                    if(i==0 || j==0){
                        if(i==0){
                            if(obstacleGrid[i][j-1]==10000){
                                obstacleGrid[i][j]=0;
                            }
                            else{
                                obstacleGrid[i][j] = obstacleGrid[0][j-1];
                            }
                        }
                        else{
                            if(obstacleGrid[i-1][j]==10000){
                                obstacleGrid[i][j]=0;
                            }
                            else{
                                obstacleGrid[i][j] = obstacleGrid[i-1][0];
                            }
                        }
                    } 
                    else if(obstacleGrid[i-1][j] == 10000 || obstacleGrid[i][j-1] == 10000) {
                        if(obstacleGrid[i-1][j] == 10000) obstacleGrid[i][j] = obstacleGrid[i][j-1];
                        else  obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    }
                    else{
                        obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]; 
                    }
                }
            }
        }

        if(obstacleGrid[n-1][m-1]==10000) return 0;

        return obstacleGrid[n-1][m-1];
    }
};

int main(){

    return 0;
}