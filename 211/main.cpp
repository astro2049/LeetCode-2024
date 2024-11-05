#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class TrieNode {
public:
    bool isEnd = false;
    TrieNode *children[26] = {};
};

class WordDictionary {
public:
    TrieNode *root = new TrieNode();

    WordDictionary() {

    }

    void addWord(string word) {
        TrieNode *n = root;
        for (auto &c: word) {
            auto &child = n->children[c - 'a'];
            if (!child) {
                child = new TrieNode();
            }
            n = child;
        }
        n->isEnd = true;
    }

    bool search(string word) {
        return searchRest(word, 0, root);
    }

    bool searchRest(string &word, int i, TrieNode *n) {
        if (i == word.length()) {
            return n->isEnd;
        }

        char c = word[i];
        if (c != '.') {
            auto &child = n->children[c - 'a'];
            if (!child) {
                return false;
            }
            return searchRest(word, i + 1, child);
        } else {
            for (auto &child: n->children) {
                if (!child) {
                    continue;
                } else {
                    if (searchRest(word, i + 1, child)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
