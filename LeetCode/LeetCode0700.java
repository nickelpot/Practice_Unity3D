// Runtime: 2 ms, faster than 93.44% of Java online submissions for Search in a Binary Search Tree.
// Memory Usage: 39.9 MB, less than 90.80% of Java online submissions for Search in a Binary Search Tree.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {

        if(root == null)
            return null;
        
        if(root.val == val)
            return root;
        
        else if(root.val > val)
            return searchBST(root.left, val);
        
        return searchBST(root.right, val);
    }
}