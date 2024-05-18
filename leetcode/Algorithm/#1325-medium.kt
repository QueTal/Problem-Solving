/**
 * 1325. Delete Leaves With a Given Value
 * https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
 */


class Solution {
    fun removeLeafNodes(node: TreeNode?, target: Int): TreeNode? {
        if (node == null) return null

        node.left = removeLeafNodes(node.left, target)
        node.right = removeLeafNodes(node.right, target)

        if (node.left == null && node.right == null && node.`val` == target) {
            return null
        }

        return node
    }
}