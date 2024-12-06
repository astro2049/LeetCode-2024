#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (auto &c: s) {
            map[c]++;
        }

        unordered_set<char> set;
        for (auto &pair: map) {
            if (pair.second == 1) {
                set.insert(pair.first);
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (set.find(s[i]) != set.end()) {
                return i;
            }
        }

        return -1;
    }
};
