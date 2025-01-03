#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

Node* build(vector<int>&pre ,int prelow,int prehigh, vector<int>&in , int inlow , int inhigh){
    if(prelow>prehigh) return nullptr;

    Node* root = new Node(pre[prelow]);

    if(prelow==prehigh) return root;

    int i = inlow;
    while(i<inhigh){
        if(in[i]==pre[prelow]) break;          // i will be at the place for root of in-order
        i++;
    }

    int leftCount = i - inlow;
    int rightCount = inhigh - i;

    root->left = build(pre ,prelow+1 ,prelow+leftCount ,in ,inlow ,i-1);
    root->right = build(pre ,prelow+leftCount+1 ,prehigh ,in ,i+1 ,inhigh);
}

int main(){
    vector<int>pre = {1,2,4,5,3,6};
    vector<int>in = {4,2,5,1,3,6};

    int n = pre.size(); //or  in.size();    both have same number of elements

    Node* x = build(pre,0,n-1,in,0,n-1);

    
    return 0;
}