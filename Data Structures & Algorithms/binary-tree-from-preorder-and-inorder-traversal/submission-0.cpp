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
    TreeNode* solver(vector<int>& preorder, vector<int>& inorder,int &p,int left,int right){
        if(left>right) return nullptr;
        int i;
        for(i=left;i<=right;i++){
            if(preorder[p]==inorder[i]){
                break;
            }
        }
        TreeNode* node = new TreeNode(inorder[i]);
        if(left<=i-1){
            node->left = solver(preorder,inorder,++p,left,i-1);
        }
        if(right>=i+1){
            node->right = solver(preorder,inorder,++p,i+1,right);
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p=0;
        return solver(preorder,inorder,p,0,preorder.size()-1);
    }
};
