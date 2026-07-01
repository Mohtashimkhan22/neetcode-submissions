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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* head=dummy;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->val<=head2->val){
                head->next=head1;
                head1=head1->next;
            }
            else{
                head->next=head2;
                head2=head2->next;
            }
            head=head->next;
        }

        if(head1!=nullptr){
            head->next=head1;
        }
        else head->next=head2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        int n = lists.size();
        ListNode* root = lists[0];
        for(int i=1;i<n;i++){
            ListNode* temp = lists[i];
            root = mergeTwoLists(root,temp);
        }
        return root;
    }
};
