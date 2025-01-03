#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};




int main(){
    Node* a = new Node(10);
    Node* b= new Node(5);
    Node* c= new Node(16);
    Node* d= new Node(1);
    Node* e= new Node(8);
    Node* f= new Node(12);
    Node* g= new Node(20);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;



    return 0;
}