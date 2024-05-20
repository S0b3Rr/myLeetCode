# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def to_list(self, root) -> int:
        _list = []
        
        if not root:
            return []
        _list.extend([root.val])
        _list.extend(self.to_list(root.left))
        _list.extend(self.to_list(root.right))
        return _list
        
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        val_list = list(filter(lambda a: a != root.val, self.to_list(root)))
        if not val_list:
            return -1
        return min(val_list)