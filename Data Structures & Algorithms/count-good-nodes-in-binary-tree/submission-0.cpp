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
    void solver(int &ans, TreeNode* root, int maxi){
        if(!root) return;
        if(root->val>=maxi){
            ans++;
            maxi=root->val;
        }
        solver(ans,root->left,maxi);
        solver(ans,root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solver(ans,root,root->val);
        return ans;
    }
};
