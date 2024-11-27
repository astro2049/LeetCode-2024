#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> memo;
    vector<string> words;

    bool wordBreak(string s, vector<string> &wordDict) {
        memo.resize(s.length(), -1);
        words = wordDict;
        return choose(0, s);
    }

    bool choose(int i, string &s) {
        if (i == s.length()) {
            return true;
        } else if (memo[i] != -1) {
            return memo[i] == 1;
        }
        memo[i] = 0;
        for (auto &word: words) {
            if (i + word.length() <= s.length() && s.substr(i, word.length()) == word) {
                if (choose(i + word.length(), s)) {
                    memo[i] = 1;
                    break;
                }
            }
        }
        return memo[i] == 1;
    }
};
