/**
 * 979. Distribute Coins in Binary Tree
 * https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
 */
 
class Solution {
    var moves = 0

    fun distributeCoins(root: TreeNode?): Int {
        dfs(root)
        return moves
    }

    fun dfs(node: TreeNode?): Int {
        if (node == null) return 0

        var left = dfs(node!!.left)
        var right = dfs(node!!.right)

        moves += abs(left) + abs(right)

        return node!!.`val` + left + right - 1

    }
}