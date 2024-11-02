#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class TrieNode {
public:
    bool isEnd = false;
    TrieNode *children[26]{};
};

class Trie {
public:
    TrieNode *root = new TrieNode;

    Trie() {

    }

    void insert(string word) {
        auto n = root;
        for (auto &c: word) {
            auto &child = n->children[c - 'a'];
            if (!child) {
                child = new TrieNode;
            }
            n = child;
        }
        n->isEnd = true;
    }

    bool search(string word) {
        auto n = root;
        for (auto &c: word) {
            auto child = n->children[c - 'a'];
            if (child) {
                n = child;
            } else {
                return false;
            }
        }
        return n->isEnd;
    }

    bool startsWith(string prefix) {
        auto n = root;
        for (auto &c: prefix) {
            auto child = n->children[c - 'a'];
            if (child) {
                n = child;
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
