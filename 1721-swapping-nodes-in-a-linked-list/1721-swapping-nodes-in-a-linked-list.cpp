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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* last = nullptr;
        ListNode* n1;
        
        for(ListNode* p = head; p != nullptr; p = p -> next) {
            if(last != nullptr)
                last = last->next;
            
            if(--k == 0) {
               n1 = p;
               last = head;
            }
        }
        swap(n1 -> val, last -> val);
        
        return head;
    }
};