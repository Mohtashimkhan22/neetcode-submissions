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
    bool flag = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((!p && q) || (p && !q) ) return false;
        if(p->val!=q->val) return false;
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right,q->right);
        return l && r;
    }
    void solver(TreeNode* root, TreeNode* subRoot){
        bool res = isSameTree(root,subRoot);

        if(res){
            flag = true;
            return;
        }
        if(root->left) solver(root->left,subRoot);
        if(root->right) solver(root->right,subRoot);
        return ;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        solver(root,subRoot);
        return flag;
    }
};
