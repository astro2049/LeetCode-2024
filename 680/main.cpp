#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool validPalindrome(string s) {
        return isPalin(0, s.length() - 1, s, true);
    }

    bool isPalin(int i, int j, string &s, bool canRemove) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++, j--;
            } else {
                if (canRemove) {
                    return isPalin(i + 1, j, s, false) || isPalin(i, j - 1, s, false);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
