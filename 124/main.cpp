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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode *root) {
        maxPathSumThru(root);

        return maxSum;
    }

    int maxPathSumThru(TreeNode *n) {
        if (!n) {
            return 0;
        }

        int leftBranchSum = max(maxPathSumThru(n->left), 0);
        int rightBranchSum = max(maxPathSumThru(n->right), 0);
        maxSum = max(maxSum, leftBranchSum + n->val + rightBranchSum);

        return max(leftBranchSum, rightBranchSum) + n->val;
    }
};
