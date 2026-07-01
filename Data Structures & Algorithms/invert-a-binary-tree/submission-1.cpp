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
    void solver(TreeNode* root,TreeNode* head){
        if(root->right) head->left=new TreeNode(root->right->val);
        if(root->left) head->right=new TreeNode(root->left->val);
        if(root->left) solver(root->left,head->right);
        if(root->right) solver(root->right,head->left);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* head = new TreeNode(root->val);
        solver(root,head);
        return head;
    }
};
