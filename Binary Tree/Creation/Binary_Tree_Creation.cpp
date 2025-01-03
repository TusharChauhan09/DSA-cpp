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

void Display_Pre(Node* root){           // pre-Display
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    Display_Pre(root->left);
    Display_Pre(root->right);
}

void Display_In(Node* root){           // In-Dispaly
    if(root==nullptr){
        return;
    }
    Display_In(root->left);
    cout<<root->data<<" ";
    Display_In(root->right);
}

void Display_Post(Node* root){        // Post Display  
    if(root==nullptr){               
        return;
    }
    Display_Post(root->left);
    Display_Post(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(7);


    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    cout<<"Pre: ";
    Display_Pre(a);
    cout<<"\n";

    cout<<"In: ";
    Display_In(a);
    cout<<"\n";

    cout<<"Post: ";
    Display_Post(a);
    cout<<"\n";
    
    
    return 0;
}