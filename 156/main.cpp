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
    TreeNode *upsideDownBinaryTree(TreeNode *n) {
        if (!n || !n->left) {
            return n;
        }

        TreeNode *newParent = upsideDownBinaryTree(n->left);

        n->left->left = n->right;
        n->left->right = n;

        n->left = nullptr, n->right = nullptr;

        return newParent;
    }
};
