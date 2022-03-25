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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list2 == NULL)
            return list1;
        if (list1 == NULL)
            return list2;
        ListNode *dummyHead = new ListNode();
        ListNode *ptr = dummyHead;
        while (list1 != NULL && list2 != NULL) {
            if (list1 -> val <= list2 -> val) {
                ListNode *node = new ListNode(list1 -> val);
                ptr -> next = node;
                list1 = list1 -> next;
            }
            else {
                ListNode *node = new ListNode(list2 -> val);
                ptr -> next = node;
                list2 = list2 -> next;
            }
            ptr = ptr -> next;
        }
        
        if (list1 != NULL)
            ptr -> next = list1;
        if (list2 != NULL)
            ptr -> next = list2;
        
        return dummyHead -> next;
    }
};