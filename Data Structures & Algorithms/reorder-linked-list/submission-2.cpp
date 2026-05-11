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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast != nullptr&& fast ->next!= nullptr){
            fast = fast->next->next;
            slow = slow ->next;
        }//find mid

        ListNode* p = nullptr;
        ListNode* c=slow->next; //head of mid
        slow->next = nullptr;
        while(c){
            ListNode* temp= c->next;
            c->next = p;
            p=c;
            c=temp;
        } 

        //merge
        ListNode* first = head;
        ListNode* sec = p;
        while (sec){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = sec->next;
            first->next = sec;
            sec->next = tmp1;
            first = tmp1;
            sec = tmp2;
        }
    }
};
