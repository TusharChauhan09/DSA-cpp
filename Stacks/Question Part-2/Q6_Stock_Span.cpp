// Q6
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// vector<int> Stock_Span(vector<int> &given){
//     reverse(given.begin(),given.end());
//     vector<int>result(given.size(),1); // OR -1
//     stack<int>s;

//     s.push(0);
//     for(int i=0;i<given.size();i++){
//         while(!s.empty() && given[s.top()]<given[i]){
//             result[s.top()] = i-s.top();
//             s.pop();
//         }
//         s.push(i);
//     }

//     reverse(result.begin(),result.end());
//     return result;
// }

vector<int> Stock_Span(vector<int> &given){
    int n = given.size();
    vector<int>ans(n);  // stores the index cur - index of prev greater 
    stack<int>st; // stores the index 
    for(int i=0;i<n;i++){
        while(!st.empty() && given[st.top()]<=given[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = i+1;
        }
        else{
            ans[i] = i-st.top();    
        }
        st.push(i);
    }
    return ans;
}

int main(){
    
    vector<int>given = {100,80,60,81,70,60,75,85};

    vector<int>result = Stock_Span(given);

    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}