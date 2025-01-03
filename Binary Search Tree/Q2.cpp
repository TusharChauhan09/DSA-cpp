/*

class Solution {
public:
    #include<iostream>
using namespace std;
class Node{
  int data;
  Node* left;
  Node* right;
  Node(int data){
      this->data=data;
      this->left=nullptr;
      this->right=nullptr;
  }
};

Node* Insertion(Node* &root,int data){
    if(root==nullptr){
        root = new Node(data);
        return root;
    }
    if(root->data>data){
        root->left = Insertion(root->left,data);
    }
    else{
        root->right = Insertion(root->right,data);
    }
    return root;
}

int main(){
    Node* root = nullptr;
    
    
}
};

*/