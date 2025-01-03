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

Node* Binary_Tree(Node* root){

    cout<<"Enter the data : \n";
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter data for inserting in left  of "<<data<<"\n";
    root->left = Binary_Tree(root->left);
    
    cout<<"Enter data for inserting in right of "<<data<<"\n";
    root->right = Binary_Tree(root->right);

    return root;
}

// (1)
void Breadth_First_Triversal(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left!=nullptr){
            q.push(temp->left);
        }

        if(temp->right!=nullptr){
            q.push(temp->right);
        }

    }
}

// (2)
void Breadth_First_Triversal_sep(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);   // seprator  level - 0

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();        

        if(temp == nullptr){     // next level / level completed
            cout<<"\n";
            if(!q.empty()){
                q.push(nullptr);
            }
        }

       else{                          // same level / level not completed

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

    root = Binary_Tree(root);      // 1 3 4 -1 -1  9 -1 -1 8 7 -1 -1 -1 

    cout<<"Printing Breadth First Triversal / Level Order Triversal : \n";

    //Breadth First Triversal(BST) / Level Order Triversal
    Breadth_First_Triversal(root);                         // 1 3 8 4 9 7

    cout<<"\n";

    cout<<"Printing Breadth First Triversal / Level Order Triversal with Sep : \n";

    //Breadth First Triversal(BST) / Level Order Triversal with Sep 
    Breadth_First_Triversal_sep(root);                         // 1 
                                                               // 3 8 
                                                               // 4 9 7

    return 0;
}