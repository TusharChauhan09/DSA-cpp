#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int>&p1 ,pair<int,int>&p2){
    // pair<value,weight>
    double r1 = (p1.first*1.0)/(p1.second*1.0);
    double r2 = (p2.first)*1.0/(p2.second*1.0);  
    return r1>r2;

    // true pick->1 argument
    // false pick->2 argument 
}

double Fractional_Knapsack(vector<int>& value, vector<int>&weights, int n ,int w){
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        arr.push_back({value[i],weights[i]});
    }
    sort(arr.begin(),arr.end(),cmp);

    double profit = 0;
    for(int i=0;i<n;i++){
        if(arr[i].second<=w){
            w -= arr[i].second;
            profit += arr[i].first;
        }
        else{
            profit += (arr[i].first*(1.0))/ (arr[i].second*(1.0)) *  w;
            w=0;
            break;
        }
    }

    return profit;
}

int main(){
    vector<int>value = {60,100,120};
    vector<int> weights = {10,20,30};
    int w = 50;
    int n=3;
    cout<<Fractional_Knapsack(value,weights,n ,w);
}