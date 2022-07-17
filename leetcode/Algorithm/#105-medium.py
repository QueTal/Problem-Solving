'''
    105. Construct Binary Tree from Preorder and Inorder Traversal
    https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    head = 0
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        try:
            cur = TreeNode(preorder[self.head])
            target_idx = inorder.index(preorder[self.head])
            
            self.head += 1
            left = self.buildTree(preorder, inorder[0: target_idx])
            right = self.buildTree(preorder, inorder[target_idx+1:])

            cur.left = left
            cur.right = right
        except:
            return None
        
        return cur