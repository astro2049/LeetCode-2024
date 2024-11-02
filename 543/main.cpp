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
    int maxDistance = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        getMaxDepth(root);
        return maxDistance - 1;
    }

    int getMaxDepth(TreeNode *n) {
        int leftDepth = n->left ? getMaxDepth(n->left) : 0;
        int rightDepth = n->right ? getMaxDepth(n->right) : 0;
        int depth = 1 + max(leftDepth, rightDepth);

        maxDistance = max(maxDistance, leftDepth + 1 + rightDepth);
        return depth;
    }
};
