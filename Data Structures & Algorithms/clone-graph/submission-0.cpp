/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* newNode = new Node(node->val);
        mp[node]=newNode;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            Node* rNode = mp[temp];
            for(auto it : temp->neighbors){
                if(mp.count(it)==0){
                    Node* child = new Node(it->val);
                    mp[it]=child;
                    q.push(it);
                }
                // cout<<mp[it]<<
                rNode->neighbors.push_back(mp[it]);
            }
        }
        return newNode;
    }
};
