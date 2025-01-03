// Q5
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

pair<int,bool> Sum_Tree(Node* root){
    if(root==nullptr){
        pair<int,bool>p = make_pair(0,true);
        return p;
    }
    if(root->left==nullptr && root->right==nullptr){          // to check for the Leaf Node mentioned in the question
        pair<int,bool>p = make_pair(root->data,true);
        return p;
    }

    pair<int,bool> left = Sum_Tree(root->left);
    pair<int,bool> right = Sum_Tree(root->right);

    bool left_check = left.first;
    bool right_check = right.first;

    int left_sum = left.second;
    int right_sum = right.second;

    bool sum = root->data == (left_sum + right_sum);

    pair<int,bool> ans;

    if(left_check && right_check && sum ){
        ans.first = true;
        ans.second =  root->data + left_sum + right_sum;     //  or 2*root->data;
        return ans;
    }
    else{
        ans.first = false;
        ans.second = -1;      
        return ans;
    }
}

bool Sum_Tree_result(Node* root){
    return Sum_Tree(root).second;
}

int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 3 1 2 -1 -1 -1 -1  
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root);    
    cout<<"\n";

    if(Sum_Tree_result(root)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}