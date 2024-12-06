#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root) {
            return {};
        }

        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);

        unordered_map<int, vector<int>> map;
        int minCol = 0, maxCol = 0;

        while (!q.empty()) {
            auto pair = q.front();
            q.pop();
            TreeNode *n = pair.first;
            int col = pair.second;
            map[col].push_back(n->val);
            minCol = min(minCol, col), maxCol = max(maxCol, col);
            if (n->left) {
                q.emplace(n->left, col - 1);
            }
            if (n->right) {
                q.emplace(n->right, col + 1);
            }
        }

        vector<vector<int>> res;
        for (int i = minCol; i <= maxCol; i++) {
            res.push_back(map[i]);
        }
        return res;
    }
};
