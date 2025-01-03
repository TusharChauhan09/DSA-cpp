// Q6
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

vector<vector<int>> ZigZag_Triversal(Node* root){

    vector<vector<int>>ans;

    if(root==nullptr){
        return ans;
    }

    queue<Node*>q;
    q.push(root);

    bool L_to_R = true;          //flag

    while(!q.empty()){
        int size = q.size();
        vector<int>t(size);    // holds the valur of each level

        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            int t_index = L_to_R? i : size-i-1;     //to check weather to pass l_to_r or r_to_l;
            t[t_index] = temp->data;                // normal insert or reverse insert

            if(temp->left!=nullptr){
                q.push(temp->left);
            }

            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
        L_to_R = !L_to_R;      // to change the direction
        ans.push_back(t);
    }
    return ans;
}

int main(){

    Node* root = nullptr;

    LevelOrder(root);      // 3 9 20 -1 -1 15 7 -1 -1 -1 -1 
    cout<<"Printing Binary Tree : \n";
    Breadth_First_Triversal_sep(root);    
    cout<<"\n";

    cout<<"ZigZag triversal: \n";
    vector<vector<int>>result = ZigZag_Triversal(root);

    for(auto i: result){
        for(auto j: i){
            cout<<j<<" ";
        }
    }

    return 0;
}