#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
using namespace std;

ll minCostToCutGrid(int n,int m,vector<ll>&horizontalCut,vector<ll>&verticalCut){
    sort(horizontalCut.rbegin(),horizontalCut.rend());
    sort(verticalCut.rbegin(),verticalCut.rend());    

    int h = 1;
    int v = 1;

    int i=0,j=0;
    int result = 0;

    while(i<horizontalCut.size() && j<verticalCut.size()){
        if(horizontalCut[i]>=verticalCut[j]){
            result = result + horizontalCut[i]*h;
            i++;
            v++;
        }
        else{
            result = result + verticalCut[j]*v;
            j++;
            h++;
        }
    }
    while(i<horizontalCut.size()){
        result = result + horizontalCut[i]*h;
        i++;
        v++;
    }
    while(j<verticalCut.size()){
        result = result + verticalCut[j]*v;
        j++;
        h++;
    }

    return result;
} 


int main(){

    int n = 6;
    int m = 4;

    vector<ll>horizontalCut = {2,1,3,1,4};
    vector<ll>verticalCut = {4,1,2};

    cout<< minCostToCutGrid(n,m,horizontalCut,verticalCut);

    return 0;
}