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
    pair<TreeNode*,TreeNode*> successor(TreeNode* root,TreeNode* prev){
        TreeNode* curr=root;
        while(curr->left){
            prev=curr;
            curr=curr->left;
        }
        return {curr,prev};
    }
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while(curr){
            if(curr->val==val){
                break;
            }
            prev=curr;
            if(curr->val>val){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        if(!curr) return root;
        // leaf node
        if(!curr->left && !curr->right){
            if(curr==root) root=nullptr;
            else if(prev->left==curr){
                prev->left = nullptr;
            }
            else prev->right=nullptr;
            delete curr;
        }
        // one child
        else if(!curr->left && curr->right){
            if(curr==root){
                root=curr->right;
            }
            else if(prev->left==curr){
                prev->left = curr->right;
            }
            else prev->right=curr->right;
            delete curr;
        }
        else if(curr->left && !curr->right){
            if(root==curr) root=curr->left;
            else if(prev->left==curr){
                prev->left = curr->left;
            }
            else prev->right=curr->left;
            delete curr;
        }
        // both child
        else{
            auto [succ,prevv] = successor(curr->right,curr);
            curr->val = succ->val;
            if(!succ->left && !succ->right){
                if(prevv->left==succ){
                    prevv->left = nullptr;
                }
                else prevv->right=nullptr;
                delete succ;
            }
            // right child
            else if(!succ->left && succ->right){
                if(prevv->left==succ){
                    prevv->left = succ->right;
                }
                else prevv->right=succ->right;
                delete succ;
            }
        }

        
        return root;
    }
};