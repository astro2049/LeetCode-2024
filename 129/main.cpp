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
    int sum = 0;

    int sumNumbers(TreeNode *root) {
        string s;
        traverse(root, s);

        return sum;
    }

    void traverse(TreeNode *n, string &s) {
        s += n->val + '0';

        if (!n->left && !n->right) {
            sum += stoi(s);
        } else {
            if (n->left) {
                traverse(n->left, s);
            }
            if (n->right) {
                traverse(n->right, s);
            }
        }
        s.pop_back();
    }
};
