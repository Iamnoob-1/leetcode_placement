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
public:
    ListNode* merge(ListNode*l1,ListNode*l2){
        ListNode*head=new ListNode(0);
        ListNode*hd=head;
        while (l1&&l2){
            if (l1->val>l2->val){
                head->next=l2;
                l2=l2->next;
            }
            else{
                head->next=l1;
                l1=l1->next;
            }
            head=head->next;
        }
        while (l1){
            head->next=l1;
            l1=l1->next;
            head=head->next;
        }
        while (l2){
            head->next=l2;
            l2=l2->next;
            head=head->next;
        }
        return hd->next;

    }
    ListNode* sortList(ListNode* head) {
        if (!head||!head->next)return head;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*temp=slow;
        while (fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=nullptr;
        ListNode*l1=sortList(head);
        ListNode*l2=sortList(slow);
        return merge(l1,l2);
    }
};