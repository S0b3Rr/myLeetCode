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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        vector<int> vals;
        while(head != NULL) {
            vals.push_back(head -> val);
            head = head -> next;
        }
        reverse(vals.begin(), vals.end());
        ListNode* dummy = new ListNode();
        ListNode* headd = new ListNode(vals[0]);
        dummy -> next = headd;
        for (int i = 1; i < vals.size(); i++) {
            ListNode* node = new ListNode(vals[i]);
            headd -> next = node;
            headd = headd -> next;
        }
        return dummy -> next;
    }
};