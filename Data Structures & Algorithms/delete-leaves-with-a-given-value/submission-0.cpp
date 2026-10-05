/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->val==target && !root->left && !root->right){
            delete root;
            return nullptr;
        }
        TreeNode* left = nullptr;
        if(root->left) left = removeLeafNodes(root->left,target);
        TreeNode* right = nullptr;
        if(root->right) right = removeLeafNodes(root->right,target);
        if(!left && !right){
            if(root->val==target){
                delete root;
                return nullptr;
            }
        }
        root->left = left;
        root->right = right;
        return root;
    }
};