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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *n, TreeNode *p, TreeNode *q) {
        if (!n || n == p || n == q) {
            return n;
        }

        auto lCandidate = lowestCommonAncestor(n->left, p, q);
        auto rCandidate = lowestCommonAncestor(n->right, p, q);

        if (lCandidate && rCandidate) {
            return n;
        } else {
            return lCandidate ? lCandidate : rCandidate;
        }
    }
};
