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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val < q->val) {
            return traverseFind(root, p, q);
        } else {
            return traverseFind(root, q, p);
        }
    }

    TreeNode *traverseFind(TreeNode *n, TreeNode *p, TreeNode *q) {
        if (n->val > q->val) {
            return traverseFind(n->left, p, q);
        } else if (n->val < p->val) {
            return traverseFind(n->right, p, q);
        } else {
            return n;
        }
    }
};
