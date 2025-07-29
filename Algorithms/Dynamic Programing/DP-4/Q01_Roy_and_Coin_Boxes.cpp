// Methode-1
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n; // no. of boxes
//     cin>>n;
    
//     vector<int>box(n+1,0);

//     int m; // day range 
//     cin>>m;

//     vector<int>l(n+1,0);
//     vector<int>r(n+1,0);

//     for(int i=0;i<m;i++){
//         int L,R;
//         cin>>L>>R;
//         l[L]++;
//         r[R]++;
//     }

//     vector<int>f(n+1,0);
//     f[1]=l[1];
//     for(int i=2;i<=n;i++){
//         f[i] = l[i] - r[i-1] + f[i-1]; 
//     }

//     vector<int>c(10000005,0);
//     for(int i=0;i<=n;i++){
//         c[f[i]]++;
//     }

//     for(int i=c.size()-2;i>=0;i--){
//         c[i] = c[i] + c[i+1];
//     }
    
//     int q;
//     cin>>q;
//     vector<int>ans;
//     while(q--){
//         int num;
//         cin>>num;
//         ans.push_back(c[num]);
//     }

//     for(auto i: ans){
//         cout<<i<<"\n";
//     }

//     return 0;
// }

// Methode-2
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; // no. of boxes
    cin>>n;
    
    vector<int>box(n+1,0);

    int m; // day range 
    cin>>m;

    vector<int>f(n+10,0); // bigger R+1 to access it can be n+2 max othervise therefore no need for n+10

    for(int i=0;i<m;i++){
        int L,R;
        cin>>L>>R;
        f[L]++;
        f[R+1]--;
    }

    for(int i=1;i<f.size();i++){
        f[i] = f[i] + f[i-1];
    }

    vector<int>c(10000005,0);
    for(int i=0;i<=n;i++){
        c[f[i]]++;
    }

    for(int i=c.size()-2;i>=0;i--){
        c[i] = c[i] + c[i+1];
    }
    
    int q;
    cin>>q;
    vector<int>ans;
    while(q--){
        int num;
        cin>>num;
        ans.push_back(c[num]);
    }

    for(auto i: ans){
        cout<<i<<"\n";
    }

    return 0;
}

// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2
// ans
// 6
// 0
// 0
// 4