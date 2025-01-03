#include<iostream>
#include<queue>
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

// Without spaces
void LevelOrder(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();    // 1
        q.pop();                   // 2
        cout<<temp->data<<" ";     // 3

        if(temp->left!=nullptr){   // 4
            q.push(temp->left);
        }
        if(temp->right!=nullptr){
            q.push(temp->right);
        }
    }
}

// With spaces
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

    cout<<"\nElements are: \n";
    LevelOrder(a);

    cout<<"\nElements are: \n";
    LevelOrder_space(a);
    
    return 0;
}