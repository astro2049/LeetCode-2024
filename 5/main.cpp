#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxLen = 0;
    int bestI, bestJ;

    string longestPalindrome(string s) {
        int i = 0;
        for (; i < s.length() - 1; i++) {
            checkPalinString(i, i, s);
            checkPalinString(i, i + 1, s);
        }
        checkPalinString(i, i, s);

        return s.substr(bestI, bestJ - bestI + 1);
    }

    void checkPalinString(int i, int j, string &s) {
        for (; i >= 0 && j < s.length(); i--, j++) {
            if (s[i] != s[j]) {
                break;
            }
        }
        i++, j--;
        int len = j - i + 1;
        if (len > maxLen) {
            maxLen = len;
            bestI = i, bestJ = j;
        }
    }
};
