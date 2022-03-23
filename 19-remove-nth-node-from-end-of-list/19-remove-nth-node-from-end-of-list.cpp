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
        ListNode* fstPtr = head;
        ListNode* secPtr = head; //maintain two pointers with n delay (pointing to the target)
        ListNode* delPtr = head; //used when the target is the last in list
        int delay = n;
        while (fstPtr != NULL) {
            fstPtr = fstPtr -> next;
            if (delay <= 0)
                secPtr = secPtr -> next;
            delay--;
        }
        //secPtr points to the target
        if (secPtr == head)
            return head -> next;
        else if (secPtr -> next == NULL) {
            while (delPtr -> next != secPtr)
                delPtr = delPtr -> next;
            delPtr -> next = NULL;
        }
        else {
            secPtr -> val = secPtr -> next -> val;
            secPtr -> next = secPtr -> next -> next;
        }
        return head;
    }
};