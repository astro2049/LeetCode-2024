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
    int sum = 0;
    int low, high;

    int rangeSumBST(TreeNode *root, int aLow, int aHigh) {
        low = aLow, high = aHigh;
        traverse(root);

        return sum;
    }

    void traverse(TreeNode *n) {
        if (n->left) {
            traverse(n->left);
        }

        if (n->val < low) {

        } else if (n->val <= high) {
            sum += n->val;
        } else {
            return;
        }

        if (n->right) {
            traverse(n->right);
        }
    }
};