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
    pair<int,int> solver(TreeNode* root){
        if(!root) return {0,0};
        // skip
        auto left = solver(root->left);
        auto right = solver(root->right);
        int skip = max(left.first,left.second) + max(right.first,right.second);
        // taken
        int taken = root->val + left.second + right.second;

        return {taken,skip};
    }
public:
    int rob(TreeNode* root) {
        auto it = solver(root);
        return max(it.first,it.second);
    }
};