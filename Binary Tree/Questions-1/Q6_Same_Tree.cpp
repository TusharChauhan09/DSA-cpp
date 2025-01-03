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

bool same(Node* root1, Node* root2){
    if(root1==nullptr && root2==nullptr){   // base case 1
        return true;
    }
    if((root1!=nullptr && root2==nullptr) || (root1==nullptr && root2!=nullptr)){    // base case 2
        return false;
    }

    if(root1->data!=root2->data){           // condition 1
        return false;
    }

    bool leftCheck = same(root1->left,root2->left);    // condition 2
    if(!leftCheck){
        return false;
    }

    bool rightCheck = same(root1->right,root2->right);  // condition 3
    if(!rightCheck){
        return false;
    }

    return true;
}

int main(){
    Node* a = new Node(1);      // root 1
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    Node* p = new Node(1);      //root 2
    Node* q = new Node(2);
    Node* r = new Node(3);
    Node* s = new Node(4);
    Node* t = new Node(5);
    Node* u = new Node(6);

    p->left = q;
    p->right = r;

    q->left = s;
    q->right = t;

    r->right = u;

    cout<<"if same then 1 else 0 : ";
    cout<<same(a,p);

    return 0;
}