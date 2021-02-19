#include <stdio.h>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::pair<int, int> findParent(TreeNode* root, int parentVal, int num, int level)
{
    if (root->val == num)
    {
        return {parentVal, level};
    }

    level++;
    if (root->left != nullptr)
    {
        findParent(root->left, root->val, num, level);
    }
    else if (root->right != nullptr)
    {
        findParent(root->right, root->val, num, level);
    }
    return {0, 0};
}

bool isCousins(TreeNode* root, int x, int y)
{
    std::pair<int, int> xParentAndLevel = findParent(root, 0, x, 0);
    std::pair<int, int> yParentAndLevel = findParent(root, 0, y, 0);

    return (xParentAndLevel.first != yParentAndLevel.first) && (xParentAndLevel.second == yParentAndLevel.second) ? true : false;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    std::cout << "Cousins in Binary Tree" << std::endl;
    std::cout << isCousins(root, 4, 5) << std::endl;
}