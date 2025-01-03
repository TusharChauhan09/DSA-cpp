// Q1
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

void LevelOrder(Node* &root){
    queue<Node*>q;
    cout<<"Enter the data of root : \n";                                 // main node

    int data ;
    cin>>data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for: "<<temp->data<<"\n";      // left 
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right node for: "<<temp->data<<"\n";     // right 
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
} 

void Breadth_First_Triversal_sep(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);  

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();        

        if(temp == nullptr){     
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

int Depth(Node* root){
    if(root == nullptr){
        return 0;
    }
    
    int leftDepth = Depth(root->left);
    int rightDepth = Depth(root->right);

    int depth = max(leftDepth , rightDepth) + 1;
    return depth;
}

int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root);    
    cout<<"\n";

    int d = Depth(root);
    cout<<"Height/Depth of Tree : "<<d;                    

    return 0;
}