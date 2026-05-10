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
        ListNode* fast = head->next;
        ListNode* slow = head;
        

        while(fast != nullptr && fast -> next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }// find mid 

        //reverse half
        ListNode* c = slow->next;
        ListNode* p = nullptr;
        slow->next = nullptr;
        while (c){
            ListNode* temp = c->next;
            c->next=p;
            p=c;
            c=temp;
        }//p is new head of half rev

        //merge
        ListNode* first = head;
        ListNode* second = p;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
