#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cs;
        int maxLen = 0;
        for (int i = 0, j = 0; j < s.length();) {
            char cj = s[j];
            if (cs.find(cj) == cs.end()) {
                cs.insert(cj);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                char ci = s[i];
                cs.erase(ci);
                i++;
            }
        }
        return maxLen;
    }
};
