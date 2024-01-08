class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        return traverse(root, low, high);
    }

    public int traverse(TreeNode node, int lo, int hi) {
        if (node == null) return 0;

        int val = node.val;
        if (node.val > hi || node.val < lo) val = 0;
        
        return val + traverse(node.left, lo, hi) + traverse(node.right, lo, hi);
    }
}