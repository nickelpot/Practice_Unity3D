//
//  LeetCode0965.cpp
//  
//
//  Created by Nuri Ra on 26.02.19.
//

#include <stdio.h>

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Univalued Binary Tree.
// Memory Usage: 11.1 MB, less than 69.47% of C++ online submissions for Univalued Binary Tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        bool bleft = (root->left == NULL || (root->val == root->left->val && isUnivalTree(root->left)));
        bool bright = (root->right == NULL || (root->val == root->right->val && isUnivalTree(root->right)));
        
        return bleft && bright;
    }
};
