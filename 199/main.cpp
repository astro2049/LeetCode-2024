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
    vector<int> res;

    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return {};
        }

        dfs(root, 0);

        return res;
    }

    void dfs(TreeNode *n, int level) {
        if (level == res.size()) {
            res.push_back(n->val);
        }

        if (n->right) {
            dfs(n->right, level + 1);
        }
        if (n->left) {
            dfs(n->left, level + 1);
        }
    }
};
