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
    bool isValidBST(TreeNode* node) {
        vector<int> inorderTree;
        inorderConvert(node, inorderTree);
        for (int i = 0; i < inorderTree.size() - 1; i++) {
            if (inorderTree[i] >= inorderTree[i + 1]) 
                return false;
        }
        return true;
    }
    
    void inorderConvert (TreeNode* node, vector<int>& inorderTree) {
        if (!node)
            return;
        inorderConvert(node -> left, inorderTree);
        inorderTree.push_back(node -> val);
        inorderConvert(node -> right, inorderTree);
    }
};