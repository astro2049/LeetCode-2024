#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        bool hasBeginWord = false;
        for (auto &word: wordList) {
            if (word == beginWord) {
                hasBeginWord = true;
                break;
            }
        }
        if (!hasBeginWord) {
            wordList.push_back(beginWord);
        }

        int m = beginWord.length();
        unordered_map<string, vector<string>> edges;
        for (int i = 0; i < wordList.size(); i++) {
            auto &word1 = wordList[i];
            for (int j = i + 1; j < wordList.size(); j++) {
                auto &word2 = wordList[j];
                int diffCount = 0;
                for (int k = 0; k < m; k++) {
                    if (word1[k] != word2[k]) {
                        diffCount++;
                        if (diffCount == 2) {
                            break;
                        }
                    }
                }
                if (diffCount == 1) {
                    edges[word1].push_back(word2);
                    edges[word2].push_back(word1);
                }
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int count = 0;
        while (!q.empty()) {
            count++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto word = q.front();
                q.pop();
                for (auto &next: edges[word]) {
                    if (next == endWord) {
                        return count + 1;
                    } else if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }

        return 0;
    }
};
