// predicessor
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right= deleteNode(root->right,key);
        }
        else{
            if(root->left==nullptr && root->right==nullptr){
                root=nullptr;
            }
            else if(root->left==nullptr || root->right==nullptr){
                if(root->left) root=root->left;
                else root=root->right;
            }
            else{
                if(root->left==nullptr) return nullptr;
                TreeNode* pred = root->left;
                while(pred->right){
                    pred = pred->right;
                }
                root->val=pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
        }
        return root;
    }
}; 

// succesor
// class Solution {
// public:
//     TreeNode* ios(TreeNode* root){
//         if(root==nullptr){
//             return nullptr;
//         }
//         TreeNode* suc = root->right;
//         while(suc->left!=nullptr){
//             suc = suc->left;
//         }
//         return suc;
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root==nullptr) return nullptr;
//         else if(root->val>key){
//             root->left = deleteNode(root->left,key);
//         }
//         else if(root->val<key){
//             root->right = deleteNode(root->right,key);
//         }
//         else{
//             //case 1:
//             if(root->left==nullptr && root->right==nullptr){
//                 root=nullptr;
//             }
//             //case 2:
//             else if(root->left==nullptr || root->right==nullptr){    // both can't be null as the above if will work
//                 if(root->left!=nullptr){
//                     root=root->left;
//                 }
//                 else{
//                     root=root->right;
//                 }
//             }
//             // case 3:
//             else{           
//                 TreeNode* temp = ios(root);
//                 root->val = temp->val;
//                 root->right = deleteNode(root->right,temp->val);
//             }
//         }
//         return root;
//     }
// };