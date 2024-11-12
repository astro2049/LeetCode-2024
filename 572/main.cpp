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
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        return traverse(root, subRoot);
    }

    bool traverse(TreeNode *n, TreeNode *subN) {
        if (!n) {
            return false;
        }
        if (isSame(n, subN)) {
            return true;
        } else {
            return traverse(n->left, subN) || traverse(n->right, subN);
        }
    }

    bool isSame(TreeNode *n1, TreeNode *n2) {
        if (n1 && n2) {
            if (n1->val == n2->val) {
                return isSame(n1->left, n2->left) && isSame(n1->right, n2->right);
            } else {
                return false;
            }
        } else if (!n1 && !n2) {
            return true;
        } else {
            return false;
        }
    }
};
