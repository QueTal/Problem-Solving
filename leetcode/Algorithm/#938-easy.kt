class Solution {
    fun rangeSumBST(root: TreeNode?, low: Int, high: Int): Int {
        root ?: return 0

        var v = 0
        if (root.`val` in low..high) {
            v = root.`val`
        }

        return rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high) + v
    }
}