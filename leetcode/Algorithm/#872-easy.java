class Solution {
    
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
        
        traverse(root1, arr1);
        traverse(root2, arr2);

        return Arrays.equals(arr1.toArray(), arr2.toArray());
    }
    public void traverse(TreeNode node, ArrayList arr) {
        if (node == null) return;

        if (node.left == null && node.right == null) {
            arr.add(node.val);
            return;
        }
        else {
            traverse(node.left, arr);
            traverse(node.right, arr);
        }
    }
}