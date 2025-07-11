class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        if(root->val==p->val || root->val==q->val) return root;
        if((root->val>p->val && root->val<q->val) || (root->val<p->val && root->val>q->val)) return root;
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        // (root->val<p->val && root->val<q->val)
        else return lowestCommonAncestor(root->right,p,q);
    }
};