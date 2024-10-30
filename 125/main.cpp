#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        for (; i < j;) {
            char ci = s[i], cj = s[j];
            if (!isAlphaNumericChar(ci)) {
                i++;
                continue;
            }
            if (!isAlphaNumericChar(cj)) {
                j--;
                continue;
            }
            if (toLowerCase(ci) == toLowerCase(cj)) {
                i++;
                j--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isAlphaNumericChar(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            c -= 'A' - 'a';
        }
        return c;
    }
};
