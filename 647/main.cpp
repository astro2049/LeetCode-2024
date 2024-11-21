#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int count = 0;

    int countSubstrings(string s) {
        int i = 0;
        for (; i < s.length() - 1; i++) {
            checkPalin(i, i, s);
            checkPalin(i, i + 1, s);
        }
        checkPalin(i, i, s);

        return count;
    }

    void checkPalin(int i, int j, string &s) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--, j++;
        }
    }
};
