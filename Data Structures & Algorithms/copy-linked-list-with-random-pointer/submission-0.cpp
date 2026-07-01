/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        mp[nullptr]=nullptr;
        Node* root = new Node(-999);
        Node* runn = head;
        Node* runn2 = root;
        while(runn){
            Node* newnode = new Node(runn->val);
            if(!root) root=newnode;
            mp[runn]=newnode;
            runn2->next=newnode;
            runn2=newnode;
            runn=runn->next;
        }
        runn = head;
        runn2 = root->next;
        while(runn){
            Node* rnode = runn->random;
            runn2->random=mp[rnode];
            runn2=runn2->next;
            runn=runn->next;
        }
        return root->next;
    }
};
