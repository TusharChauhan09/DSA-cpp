#include<iostream>
using namespace std;

class Node{             // Node Creation
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

Node* Binary_Tree(Node* root){         // Binary Tree Creation

    cout<<"Enter the data : \n";
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter data for inserting in left  of "<<data<<"\n";
    root->left = Binary_Tree(root->left);
    
    cout<<"Enter data for inserting in right of "<<data<<"\n";
    root->right = Binary_Tree(root->right);

    return root;
}

int main(){

    Node* root = nullptr;

    //creation
    root = Binary_Tree(root);           // 1 3 4 -1 -1  9 -1 -1 8 7 -1 -1 -1

    return 0;
}