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
    ListNode* reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*forw=nullptr;
        while (curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        //find the middle if length is odd skip the middle node .If the list has odd length, fast ends on the last node (not nullptr). reverse the second half after this 
// If the list has even length, fast becomes nullptr.
        ListNode*slow=head;
        ListNode* fast=head;
        while (fast&& fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast!=nullptr){
            slow=slow->next;
        }
        slow=reverse(slow);



        ListNode*temp=head;
        while (slow){
            if (slow->val!=temp->val)return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};