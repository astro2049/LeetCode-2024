#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> combos;
    unordered_map<char, vector<char>> letters = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string s;
        choose(0, s, digits);

        return combos;
    }

    void choose(int i, string &s, string &digits) {
        if (i == digits.size()) {
            combos.push_back(s);
            return;
        }
        for (auto &letter: letters[digits[i]]) {
            s += letter;
            choose(i + 1, s, digits);
            s.pop_back();
        }
    }
};
