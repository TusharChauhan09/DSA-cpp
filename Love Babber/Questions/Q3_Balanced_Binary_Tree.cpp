// Q3
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


// Methode-1
int Depth(Node* root){                // For Depth
    if(root == nullptr){ 
        return 0;
    }
    
    int leftDepth = Depth(root->left);
    int rightDepth = Depth(root->right);

    int depth = max(leftDepth , rightDepth) + 1;
    return depth;
}

bool Balanced_Binary_Tree(Node* root){       // For balaced_check
    if(root == nullptr){
        return true;
    }

    bool left_check = Balanced_Binary_Tree(root->left);
    bool right_check = Balanced_Binary_Tree(root->right);

    bool diff = abs(Depth(root->left)-Depth(root->right))<=1;

    if(left_check && right_check && diff){
        return true;
    }
    else{
        return false;
    }
}


// Methode-2 
pair<bool,int> Balanced_Binary_Tree_op(Node* root){     // balanced_check & Depth
    if(root==nullptr){
        pair<bool,int>p  = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = Balanced_Binary_Tree_op(root->left);
    pair<bool,int> right = Balanced_Binary_Tree_op(root->right);

    bool left_check = left.first;
    bool right_check = right.first;
    bool diff = abs(left.second - right.second)<=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;
    

    if(left_check && right_check && diff){
        ans.first = true;     
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool Balanced_Binary_Tree_optimize(Node* root){
    return Balanced_Binary_Tree_op(root).first;
}


int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 3 9 20 -1 -1 15 7 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root);    
    cout<<"\n";

    int result1 = Balanced_Binary_Tree(root);

    if(result1){
        cout<<"Balanced \n";
    }      
    else{
        cout<<"Not Balanced\n";
    }

    cout<<"\n";

    int result2 = Balanced_Binary_Tree_optimize(root);

    if(result2){
        cout<<"Balanced \n";
    }      
    else{
        cout<<"Not Balanced\n";
    }

    return 0;
}