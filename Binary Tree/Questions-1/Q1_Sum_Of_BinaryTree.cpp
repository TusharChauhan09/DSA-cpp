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

int sum(Node* root){
    if(root==nullptr){
        return 0;
    }
    int Tree_sum = root->data + sum(root->left) + sum(root->right);             
    return Tree_sum;
}

int main(){
    Node* a = new Node(5);
    Node* b = new Node(4);
    Node* c = new Node(3);
    Node* d = new Node(6);
    Node* e = new Node(5);
    Node* f = new Node(1);


    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    cout<<"The Tree sum is: ";
    cout<<sum(a);

    return 0;
}