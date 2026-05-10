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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n>0){ //move right to the n spot
            right = right ->next;
            n--;
        }
        while (right != nullptr){ // move right to the end of the list so left will be at n-1 spot
            left = left->next;
            right = right ->next;
        }

        left ->next = left ->next->next; // remove the unwanted node
        return dummy->next; //dummy start at0 so we need the next;
    }
};
