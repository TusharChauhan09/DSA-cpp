#include<iostream>
#include<queue>
#include<climits>
#include<vector> // Need to include <vector> to use vector
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

// Function to construct a binary tree from level-order representation
Node* Construct_LevelOrder(vector<int> v){
    if(v.empty()) return nullptr;  // Handle case of empty input
    queue<Node*> q;
    Node* root = new Node(v[0]);
    q.push(root);
    int i = 1;

    while(!q.empty() && i < v.size()){
        Node* temp = q.front();
        q.pop();

        if(i < v.size() && v[i] != INT_MIN){
            temp->left = new Node(v[i]);
            q.push(temp->left);
        }
        i++;

        if(i < v.size() && v[i] != INT_MIN){
            temp->right = new Node(v[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

// Helper function to count paths starting from the current node
void result(Node* root, long long targetSum, int& count){
    if(root == nullptr) return;
    
    if(targetSum == root->data){
        count++;
    }

    // Check left and right subtrees
    result(root->left, targetSum - root->data, count);
    result(root->right, targetSum - root->data, count);
}

// Function to find all paths that sum to the target value
int pathSum(Node* root, int targetSum){
    if(root == nullptr){
        return 0;
    }

    // Count paths that start from the current node
    int count = 0;
    result(root, (long long)targetSum, count);

    // Count paths from the left and right subtrees
    int leftCount = pathSum(root->left, targetSum);
    int rightCount = pathSum(root->right, targetSum);

    // Return total count of paths
    return count + leftCount + rightCount;
}

int main(){
    vector<int> a = {10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1};
    Node* root = Construct_LevelOrder(a);

    int targetSum = 22;
    cout << pathSum(root, targetSum);

    return 0;
}
