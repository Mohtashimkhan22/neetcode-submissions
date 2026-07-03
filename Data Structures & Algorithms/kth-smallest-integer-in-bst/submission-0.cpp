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
    int ans = 0;
    void solver(TreeNode* root,int k, int &count){
        if(!root) return;
        
        solver(root->left,k,count);
        count++;
        if(k==count){
            ans=root->val;
            return;
        }
        solver(root->right,k,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        solver(root,k,count);
        return ans;
    }
};
