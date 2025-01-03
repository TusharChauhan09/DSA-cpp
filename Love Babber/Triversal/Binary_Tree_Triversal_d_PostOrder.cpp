#include<iostream>
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

Node* Binary_Tree(Node* root){         

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

void PostOrder(Node* root){    // LRN
    if(root==nullptr){
        return ;
    }

    PostOrder(root->left);     

    PostOrder(root->right);

    cout<<root->data<<" ";
}

int main(){

    Node* root = nullptr;

    //creation
    root = Binary_Tree(root);           // 1 3 4 -1 -1  9 -1 -1 8 7 -1 -1 -1

    cout<<"PostOrder Triversal : \n";
    PostOrder(root);                      // 4 9 3 7 8 1

    return 0;
}