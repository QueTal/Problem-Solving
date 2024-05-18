/**
 * 2331. Evaluate Boolean Binary Tree
 * https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
 */


class Solution {
    fun evaluateTree(node: TreeNode): Boolean {
        if (node.`val` == 0) return false
        else if (node.`val`== 1) return true

        val left = evaluateTree(node.left)
        val right = evaluateTree(node.right)

        return if (node.`val` == 2) (left || right) else (left && right)
    }
}
