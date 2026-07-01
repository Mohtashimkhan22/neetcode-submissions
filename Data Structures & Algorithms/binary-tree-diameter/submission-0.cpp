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
    int maxi = 0;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    void solver(TreeNode* head){
        int l = maxDepth(head->left);
        int r = maxDepth(head->right);

        maxi=max(l+r,maxi);
        if(head->left) solver(head->left);
        if(head->right) solver(head->right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solver(root);
        return maxi;
    }
};
