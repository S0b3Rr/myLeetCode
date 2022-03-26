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
    ListNode* deleteDuplicates(ListNode* headd) {
        if (headd == NULL)
            return NULL;
        ListNode* head = headd;
        while (head && head -> next) {
            if (head -> val == head -> next -> val) {
                head -> next = head -> next -> next; 
                continue;
            }
            head = head -> next;
        }
        return headd;
    }
};