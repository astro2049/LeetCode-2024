#include <iostream>

using namespace std;

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
    bool balanced = true;

    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }

        getHeight(root);
        return balanced;
    }

    int getHeight(TreeNode *n) {
        if (!n->left && !n->right) {
            return 1;
        }
        int leftHeight = n->left ? getHeight(n->left) : 0;
        int rightHeight = n->right ? getHeight(n->right) : 0;
        if (abs(leftHeight - rightHeight) > 1) {
            balanced = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};
