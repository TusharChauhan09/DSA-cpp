class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur = root;
        while(cur!=nullptr){
            if(cur->left!=nullptr){ // find predecessor
                TreeNode* pred = cur->left;
                while(pred->right!=nullptr && pred->right!=cur){
                    pred = pred->right;
                }
                if(pred->right==nullptr){ //link
                    pred->right=cur;
                    cur = cur->left;
                }
                else{ // unlink : pred->right==cur
                    pred->right=nullptr;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
            else{ // no predecssor
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};