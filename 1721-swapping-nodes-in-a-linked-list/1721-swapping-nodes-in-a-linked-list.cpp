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
        vector<int> nums;
        while (head) {
            nums.push_back(head -> val);
            head = head -> next;
        }
        int index = nums.size() - k;
        swap(nums[k - 1], nums[index]);
        ListNode* dummy = new ListNode();
        ListNode* listPtr = dummy;
        auto ptr = nums.begin();
        while (ptr != nums.end()) {
            listPtr -> next = new ListNode(*ptr);
            listPtr = listPtr -> next;
            ptr++;
        }
        return dummy -> next;
    }
};