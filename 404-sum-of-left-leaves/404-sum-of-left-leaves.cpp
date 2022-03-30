/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root, int* left_sum, bool left_child) {
        if (!root) 
            return;
        //check if its a leaf node
        if (root -> left == NULL && root -> right == NULL && left_child) {
            *left_sum += root->val;
            return;
        }
        
        func(root->left, left_sum, true);
        func(root->right, left_sum, false);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        func(root, &ans, false);
        
        return ans;
    }
};