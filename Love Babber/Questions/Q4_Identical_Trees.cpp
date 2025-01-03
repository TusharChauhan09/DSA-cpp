// Q4
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

bool Same_Tree(Node* root1 , Node* root2){
    if(root1==nullptr &&  root2==nullptr){
        return true;
    }
    if(root1==nullptr && root2!=nullptr){
        return false;
    }
    if(root1!=nullptr && root2==nullptr){
        return false;
    }


    bool left = Same_Tree(root1->left,root2->left);
    bool right = Same_Tree(root1->right,root1->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

bool Sum_Tree_result(Node* root1 , Node* root2){
    bool result = Same_Tree(root1 , root2);
    return result;
}

int main(){

    Node* root1 = nullptr;

    LevelOrder(root1);      // 1 2 3 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root1);    
    cout<<"\n";

    Node* root2 = nullptr;
    LevelOrder(root2);      // 1 2 3 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root2);    
    cout<<"\n";

    if(Sum_Tree_result(root1,root2)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}