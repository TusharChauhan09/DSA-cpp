class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        if(root->val>val){
            if(root->left==nullptr) root->left = new TreeNode(val);
            else insertIntoBST(root->left,val);
        }
        // root->val<val
        else{
            if(root->right==nullptr) root->right = new TreeNode(val);
            else insertIntoBST(root->right,val);
        }
        return root;
    }
};