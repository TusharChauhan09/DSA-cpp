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

int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 1 3 8 4 9 7 -1 -1 -1 -1 -1 -1 -1 

    cout<<"Printing Breadth First Triversal / Level Order Triversal with Sep : \n";

    //Breadth First Triversal(BST) / Level Order Triversal with Sep 
    Breadth_First_Triversal_sep(root);                         // 1 
                                                               // 3 8 
                                                               // 4 9 7

    return 0;
}