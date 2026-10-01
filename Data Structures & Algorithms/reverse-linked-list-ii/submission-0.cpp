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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* prev = nullptr;
        ListNode *start=nullptr, *end=nullptr, *runner=head;
        while(runner!=nullptr){
            if(count==left){
                start=runner;
            }
            if(count==right){
                end=runner;
                break;
            }
            if(!start) prev = runner;
            count++;
            runner=runner->next;
        }
        ListNode* temp = runner->next;
        end->next=nullptr;
        if(prev) prev->next=nullptr;
        ListNode* rev = reverseList(start);
        if(prev) prev->next=end;
        else head=end;
        start->next=temp;
        return head;
    }
};