#include<iostream>
#include<vector>
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

bool Exist_In_Tree(Node* root, Node* Target){
    if(root==nullptr){
        return false;
    }
    if(root==Target){
        return true;
    }
    return Exist_In_Tree(root->left,Target) || Exist_In_Tree(root->right,Target); ;
}
Node* Lowest_Common_Ancestor(Node* root,Node* p, Node* q){
    if(root==p || root==q){                             // p=>root or q=>root
        return root;
    }
    else if((Exist_In_Tree(root->left,p) && Exist_In_Tree(root->right,q)) || (!Exist_In_Tree(root->right,p) && Exist_In_Tree(root->left,q))){    // (p=>left and q=>right) or (p=>right and q=>left)
        return root;                                                                                                                                                           
    }
    else if(Exist_In_Tree(root->left,p) && Exist_In_Tree(root->left,q)){         // p=>left and q=>left
        return Lowest_Common_Ancestor(root->left,p, q);
    }
    else{                  // p=>left and q=>right
        return Lowest_Common_Ancestor(root->right,p, q);
    }
}

// OR

/*
Node* Lowest_Common_Ancestor(Node* root,Node* p, Node* q){
    if(Exist_In_Tree(root->left,p) && Exist_In_Tree(root->left,q)){         // p=>left and q=>left
        return Lowest_Common_Ancestor(root->left,p, q);
    }
    else{                  // p=>left and q=>right
        return Lowest_Common_Ancestor(root->right,p, q);
    }
    return root
}
*/

int main(){
    Node* a = new Node(3);
    Node* b = new Node(5);
    Node* c = new Node(1);
    Node* d = new Node(6);
    Node* e = new Node(2);
    Node* f = new Node(0);
    Node* g = new Node(8);
    Node* h = new Node(7);
    Node* j = new Node(4);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    e->left = h;
    e->right = j;
    
    c->right = f;
    c->right = g;
    
    Node* temp = Lowest_Common_Ancestor(a,h,j);
    cout<<"The Lowest Common Ancestor is : ";
    cout<<temp->data;

    return 0;
}