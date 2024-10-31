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
    int depth = 0;

    int maxDepth(TreeNode *root) {
        if (!root) {
            return depth;
        }

        traverse(root, 0);
        return depth;
    }

    void traverse(TreeNode *n, int currentDepth) {
        currentDepth++;
        depth = max(depth, currentDepth);
        if (n->left) {
            traverse(n->left, currentDepth);
        }
        if (n->right) {
            traverse(n->right, currentDepth);
        }
    }
};
