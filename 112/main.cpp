#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        int sum = 0;
        return traverse(root, sum, targetSum);
    }

    bool traverse(TreeNode *n, int sum, int &targetSum) {
        sum += n->val;
        if (!n->left && !n->right) {
            return sum == targetSum;
        }
        return (n->left && traverse(n->left, sum, targetSum)) || (n->right && traverse(n->right, sum, targetSum));
    }
};
