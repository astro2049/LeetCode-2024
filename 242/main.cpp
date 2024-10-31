#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> ms, mt;
        for (int i = 0; i < s.length(); i++) {
            ms[s[i]]++, mt[t[i]]++;
        }
        if (ms.size() != mt.size()) {
            return false;
        }
        for (auto &kv: ms) {
            char c = kv.first;
            int count = kv.second;
            if (mt.find(c) != mt.end() && count == mt[c]) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
