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

void leftBoundry(Node* root){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        return;
    }  
    cout<<root->data<<" ";
    leftBoundry(root->left);
    if(root->left==nullptr){
        leftBoundry(root->right);
    }
}
void leafBoundry(Node* root){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        cout<<root->data<<" ";
    }  
    leafBoundry(root->left);
    leafBoundry(root->right);
}
void rightBoundry(Node* root){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        return;
    }  
    rightBoundry(root->right);
    if(root->right==nullptr){
        leftBoundry(root->left);
    }
    cout<<root->data<<" ";
}
void Boundary(Node* root){
    leftBoundry(root);
    leafBoundry(root);
    rightBoundry(root->right);
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

int main(){
    // construct
    // vector<int>v = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,INT_MIN,27,INT_MIN,28};
    // vector<int>v = {1, 2, 3, 4, 5, 6, INT_MIN, INT_MIN, 7, 8, 9, 10};
    vector<int>v = {1,INT_MIN,87,INT_MIN,64,INT_MIN,INT_MIN};
    Node* root = Construct_LevelOrder(v);

    LevelOrder_space(root);

    cout<<"Boundry is : \n";
    Boundary(root);

    return 0;
}