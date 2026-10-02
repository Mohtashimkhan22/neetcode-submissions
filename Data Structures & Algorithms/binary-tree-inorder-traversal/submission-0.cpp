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
    void solver(TreeNode* root, vector<int> &res){
        if(!root) return;
        solver(root->left,res);
        res.push_back(root->val);
        solver(root->right,res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solver(root,res);
        return res;
    }
};