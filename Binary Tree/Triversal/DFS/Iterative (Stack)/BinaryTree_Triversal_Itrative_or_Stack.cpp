#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
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

vector<int> vector_Pre(Node* root){           // Pre-order
    vector<int>v;
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();

        v.push_back(temp->data);
        if(temp->right!=nullptr){
            s.push(temp->right);
        }
        if(temp->left!=nullptr){
            s.push(temp->left);
        }
    }
    return v;
}

vector<int> vector_Post(Node* root){               // Post-order
    vector<int>v;
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();

        v.push_back(temp->data);
        if(temp->left!=nullptr){
            s.push(temp->left);
        }
        if(temp->right!=nullptr){
            s.push(temp->right);
        }
    }
    reverse(v.begin(),v.end());
    return v;
}

vector<int> vector_In(Node* root){                       // In order
    vector<int>v;
    stack<Node*>s;
    Node* node = root;

    while(node!=nullptr || !s.empty()){
        if(node!=nullptr){
            s.push(node);
            node = node->left;
        }
        else{
           Node* temp = s.top();
            s.pop();
            v.push_back(temp->data);
            node = temp->right;
        }
    }
    return v;
}

Node* Construct_LevelOrder(vector<int>v){    // for construction only 
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
    vector<int>v = {1,2,3,4,5,6,7};
    Node* root = Construct_LevelOrder(v);

    cout<<"Pre: ";
    vector<int> pre = vector_Pre(root);
    for(auto i:pre){
        cout<<i<<" ";
    }

    cout<<"\nPost: ";
    vector<int> post = vector_Post(root);
    for(auto i:post){
        cout<<i<<" ";
    }

    cout<<"\nIn: ";
    vector<int> In = vector_In(root);
    for(auto i:In){
        cout<<i<<" ";
    }
    
    return 0;
}
