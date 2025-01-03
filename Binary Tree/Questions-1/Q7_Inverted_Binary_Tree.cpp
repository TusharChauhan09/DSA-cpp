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

void Display(Node* root){           // In-Dispaly
    if(root==nullptr){
        return;
    }
    Display(root->left);
    cout<<root->data<<" ";
    Display(root->right);
}

void invert(Node* &root){
    if(root->left==nullptr && root->right==nullptr){
        return ;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert(root->left);
    invert(root->right);
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    cout<<"before Inversion: ";
    Display(a);
    cout<<"\n";

    invert(a);

    cout<<"After Inversion: ";
    Display(a);

    return 0;
}