#include <iostream>
#include <vector>

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
    vector<int> nums;

    int kthSmallest(TreeNode *root, int k) {
        traverse(root);

        return nums[k - 1];
    }

    void traverse(TreeNode *n) {
        if (n->left) {
            traverse(n->left);
        }
        nums.push_back(n->val);
        if (n->right) {
            traverse(n->right);
        }
    }
};