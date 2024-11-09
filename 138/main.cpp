#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        Node *n = head;
        unordered_map<Node *, Node *> map;
        while (n) {
            map[n] = new Node(n->val);
            n = n->next;
        }

        for (auto &pair: map) {
            auto nOriginal = pair.first, nNew = pair.second;
            nNew->next = nOriginal->next ? map[nOriginal->next] : nullptr;
            nNew->random = nOriginal->random ? map[nOriginal->random] : nullptr;
        }

        return map[head];
    }
};
