#include<iostream>
#include<vector>
#include<limits.h>
#include <algorithm> 

#define inf INT_MAX

using namespace std;

vector<int> getDigits(int n){
    vector<int>digits;
    while(n>0){
        int d = n%10;
        if(d!=0){
            digits.push_back(d);
        }
        n /= 10;
    }
    return digits;
}

int rec(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    vector<int>digits = getDigits(n);
    int result = INT_MAX;
    for(int i=0;i<digits.size();i++){
        result = min(result, rec(n-digits[i]));
    }
    return 1 + result;
}
 
int main(){

    int n;
    cin>>n;
    int ans = rec(n);

    cout<<ans; 

    return 0;
}