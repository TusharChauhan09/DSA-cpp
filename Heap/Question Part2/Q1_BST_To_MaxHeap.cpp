#include<iostream>
#include<vector>
#include<queue>
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

void revInOrder(Node* root , vector<int>&dec){
    if(!root) return;
    revInOrder(root->right,dec);
    dec.push_back(root->data);
    revInOrder(root->left,dec);
}

void preOrder(Node* &root, vector<int>dec,int &i){
    if(!root) return;
    root->data = dec[i++];
    preOrder(root->left,dec,i);
    preOrder(root->right,dec,i);
}


void LevelOrder_space(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp = q.front();    // 1
        q.pop();                   // 2

        if(temp==nullptr){         // extra for space
            cout<<"\n";
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";     // 3

            if(temp->left!=nullptr){   // 4
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
    }
}

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

    LevelOrder_space(a);

    vector<int>dec;
    revInOrder(a,dec);

    int i=0;
    preOrder(a,dec,i);

    LevelOrder_space(a);

    return 0;
}