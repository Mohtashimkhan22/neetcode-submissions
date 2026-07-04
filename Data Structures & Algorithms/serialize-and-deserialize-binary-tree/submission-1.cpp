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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                ans += "N,";
                continue;
            }

            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="N") return nullptr;
        int i=0;
        string str;
        while(i<data.size() && data[i]!=','){
            str+=data[i];
            i++;
        }
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        for(++i;i<data.size();){
            TreeNode* node = q.front();
            q.pop();
            string str1,str2;
            while(data[i]!=','){
                str1+=data[i];
                i++;
            }
            i++;
            while(data[i]!=','){
                str2+=data[i];
                i++;
            }
            i++;
            if(str1!="N"){
                node->left=new TreeNode(stoi(str1));
                q.push(node->left);
            }
            if(str2!="N"){
                node->right=new TreeNode(stoi(str2));
                q.push(node->right);
            }
        }
        return root;
    }
};
