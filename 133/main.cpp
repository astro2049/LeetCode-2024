#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<Node *, Node *> map;
        queue<Node *> q;
        q.push(node);
        map[node] = new Node(node->val);

        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            for (auto &neighbor: n->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    q.push(neighbor);
                    map[neighbor] = new Node(neighbor->val);
                }
                map[n]->neighbors.push_back(map[neighbor]);
            }
        }

        return map[node];
    }
};
