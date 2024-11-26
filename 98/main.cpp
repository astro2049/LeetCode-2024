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
    bool isValidBST(TreeNode *root) {
        return traverse(root->left, LONG_LONG_MIN, root->val) && traverse(root->right, root->val, LONG_LONG_MAX);
    }

    bool traverse(TreeNode *n, long long min, long long max) {
        if (!n) {
            return true;
        }
        return min < n->val && n->val < max && traverse(n->left, min, n->val) && traverse(n->right, n->val, max);
    }
};
