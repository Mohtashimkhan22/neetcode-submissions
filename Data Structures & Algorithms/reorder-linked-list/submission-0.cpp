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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* root2 = reverseList(slow->next);
        slow->next=nullptr;
        ListNode* root1 = head;


        while(root2!=nullptr){
            ListNode* r1 = root1->next;
            ListNode* r2 = root2->next;
            // cout<<root1->val<<" "<<root2->val<<" ";
            root1->next=root2;
            root2->next = r1;
            root1=r1;
            root2=r2;
        }
    }
};
