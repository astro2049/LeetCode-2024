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
    TreeNode *invertTree(TreeNode *root) {
        swapLeftRightChildren(root);
        return root;
    }

    void swapLeftRightChildren(TreeNode *n) {
        if (!n) {
            return;
        }
        TreeNode *temp = n->left;
        n->left = n->right;
        n->right = temp;
        swapLeftRightChildren(n->left);
        swapLeftRightChildren(n->right);
    }
};
