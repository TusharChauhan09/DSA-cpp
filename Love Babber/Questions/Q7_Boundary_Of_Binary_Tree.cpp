// Q7
#include<iostream>
#include<queue>
#include<vector>
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

void TriverseLeft(Node* root, vector<int>&ans){      // (1)
    if((root==nullptr) || (root->left==nullptr && root->left==nullptr)){
        return ;
    }

    ans.push_back(root->data);
    if(root->left!=nullptr){
        TriverseLeft(root->left,ans);
    }
    else{
        TriverseLeft(root->right,ans);
    }
}

void TriverseLeaf(Node* root, vector<int>&ans){          //(2) 
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(root->data);
    }

    TriverseLeaf(root->left,ans);
    TriverseLeaf(root->right,ans);

}

void TriverseRight( Node* root, vector<int>&ans){                       //(3)
    if((root==nullptr) || (root->left==nullptr && root->right==nullptr)){
        return ;
    }             

    if(root->right!=nullptr){
        TriverseRight(root->right,ans);
    }
    else{
        TriverseRight(root->left,ans);
    }

    ans.push_back(root->data);

}

vector<int> Boundary_OF_Tree(Node* root){
    vector<int>ans;
    if(root==nullptr){
        return ans;
    }

    ans.push_back(root->data); 

    // (1)
    TriverseLeft(root->left,ans);       

    // (2)
    TriverseLeaf(root->left,ans);
    TriverseLeaf(root->right,ans);

    // (3) 
    TriverseRight(root->right,ans);

    return ans;
}



int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 1 2 3 4 5 6 -1 -1 -1 7 8 9 10 -1 -1 -1 -1 -1 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root);    
    cout<<"\n";

    vector<int>result = Boundary_OF_Tree(root);
    cout<<"Boundary Of Binary Tree: \n";
    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}