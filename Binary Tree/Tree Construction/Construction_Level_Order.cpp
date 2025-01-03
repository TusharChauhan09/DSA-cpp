#include<iostream>
#include<queue>
#include<climits>
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

void LevelOrder_space(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp = q.front();  
        q.pop();                   

        if(temp==nullptr){         
            cout<<"\n";
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";     

            if(temp->left!=nullptr){  
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
    }
}

Node* Construct_LevelOrder(vector<int>v){
    queue<Node*>q;
    Node* root = new Node(v[0]);
    q.push(root);
    int i=1;
    int j=2;

    while(q.size()>0 && i<v.size()){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;

        if(v[i]!=INT_MIN) l = new Node(v[i]);
        else l = nullptr;

        if(j!=v.size() && v[j]!=INT_MIN) r = new Node(v[j]);
        else r = nullptr;

        temp->left=l;
        temp->right=r;

        if(l!=nullptr) q.push(l);
        if(r!=nullptr) q.push(r);

        i+=2; j+=2;
    }
    
    return root;
}

int main(){
    // construct
    vector<int>v = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    Node* root = Construct_LevelOrder(v);

    LevelOrder_space(root);
    return 0;
}