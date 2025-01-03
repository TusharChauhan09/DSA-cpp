/*
// method-1
class Solution {
public:
    long long maxCheck(TreeNode* root){
        if(root==nullptr) return LLONG_MIN;
        return (max((long long)(root->val),max(maxCheck(root->left),maxCheck(root->right))));
    }
    long long minCheck(TreeNode* root){
        if(root==nullptr) return LLONG_MAX;
        return (min((long long)(root->val),min(minCheck(root->left),minCheck(root->right))));
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true ;
        if(root->left==nullptr && root->right==nullptr) return true;
        else if((long long)root->val<=maxCheck(root->left)) return false;  //opposite condition 
        else if((long long)root->val>=minCheck(root->right)) return false; //opposite condition
        return (isValidBST(root->left) && isValidBST(root->right));
    }
};

Methode-2



*/