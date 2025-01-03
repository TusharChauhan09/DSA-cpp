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

int level(Node* root){
    if(root==nullptr){
        return 0;
    } 
    int Tree_level = 1 + max(level(root->left),level(root->right));
    return Tree_level;
}

// methode 1
int max_diameter1 = 0;        // global variable
int diameter1(Node* root){
    if(root==nullptr){
        return 0;
    } 
    int Tree_diameter = level(root->left) + level(root->right);
    max_diameter1 = max(max_diameter1,Tree_diameter);
    diameter1(root->left);
    diameter1(root->right);
    return max_diameter1;
}

//methode 2
void helper(Node* root,int &max_diameter2){       // helper function / no gobal variable
    if(root==nullptr){
        return;
    } 
    int Tree_diameter = level(root->left) + level(root->right);
    max_diameter2 = max(max_diameter2,Tree_diameter);
    helper(root->left, max_diameter2);
    helper(root->right, max_diameter2);
}
int diameter2(Node* root){
    int max_diameter2=0;
    helper(root,max_diameter2);
    return max_diameter2;
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    cout<<"The Tree Diamenter is: ";
    cout<<diameter1(a);
    cout<<"\n";

    cout<<"The Tree Diamenter is: ";
    cout<<diameter2(a);
    cout<<"\n";

    return 0;
}