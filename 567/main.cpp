#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int m1[26] = {}, m2[26] = {};
        for (auto &c: s1) {
            m1[c - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            m2[s2[i] - 'a']++;
        }

        int checks = 0;
        for (int i = 0; i < 26; i++) {
            if (m1[i] == m2[i]) {
                checks++;
            }
        }
        if (checks == 26) {
            return true;
        }

        for (int l = 0, r = s1.length(); r < s2.length(); l++, r++) {
            auto c1 = s2[l] - 'a', c2 = s2[r] - 'a';
            m2[c1]--;
            if (m1[c1] == m2[c1]) {
                checks++;
            } else if (m1[c1] == m2[c1] + 1) {
                checks--;
            }
            m2[c2]++;
            if (m1[c2] == m2[c2]) {
                checks++;
            } else if (m1[c2] == m2[c2] - 1) {
                checks--;
            }
            if (checks == 26) {
                return true;
            }
        }
        return false;
    }
};
