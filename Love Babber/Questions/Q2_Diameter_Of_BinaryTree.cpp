// Q2
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

int Diameter(Node* root){               // For Diameter
    if(root == nullptr){
        return 0;
    }
    
    int leftDiameter = Diameter(root->left);
    int rightDiameter = Diameter(root->right);
    int left_right = Depth(root->left) + 1 + Depth(root->right);

    int diameter = max(max(leftDiameter, rightDiameter), left_right); 

    return diameter;
}


// Methode-2
pair<int,int> Diameter_op(Node* root){        // Diameter & Depth
    if(root==nullptr){
        pair<int,int>p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = Diameter_op(root->left);
    pair<int,int> right = Diameter_op(root->right);
    
    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int left_right = left.second + 1 + right.second;

    pair<int,int> ans;
    ans.first = max(max(leftDiameter, rightDiameter), left_right);
    ans.second = max(left.second,right.second)+1;

    return ans;
}

int Diameter_Optimize(Node* root){
    return Diameter_op(root).first;
}


int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root);    
    cout<<"\n";

    int d1 = Diameter(root);
    cout<<"Diameter of Tree : "<<d1;

    cout<<"\n"; 

    int d2 = Diameter_Optimize(root); 
    cout<<"Diameter of Tree : "<<d2;                   

    return 0;
}