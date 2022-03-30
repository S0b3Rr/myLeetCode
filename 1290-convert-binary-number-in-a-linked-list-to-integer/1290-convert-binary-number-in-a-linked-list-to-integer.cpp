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
    int getDecimalValue(ListNode* head) {
        ListNode* count = head, *ptr = head;
        int counter = 0, ans = 0;
        while(count != NULL){
            counter++;
            count = count -> next;
        }
        while(counter--){
            ans += ptr -> val * pow(2, counter);
            ptr = ptr -> next;
        }
        return ans;
    }
};