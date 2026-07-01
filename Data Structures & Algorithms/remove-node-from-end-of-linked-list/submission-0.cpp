/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = reverseList(head);
        ListNode* runn = root;
        for(int i=1;i<n-1;i++){
            runn=runn->next;
        }
        ListNode* sec = runn->next;
        if(!sec){
            delete runn;
            return nullptr;
        }
        else if(n==1){
            root=sec;
            delete runn;
        }
        else {
            runn->next=sec->next;
            delete sec;
        }
        head = reverseList(root);
        return head;
    }
};
