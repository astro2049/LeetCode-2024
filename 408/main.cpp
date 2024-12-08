#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        for (; i < abbr.size() && j < word.size();) {
            if ('a' <= abbr[i] && abbr[i] <= 'z') {
                if (abbr[i] == word[j]) {
                    i++, j++;
                } else {
                    return false;
                }
            } else {
                if (abbr[i] == '0') {
                    return false;
                }

                // substring length: max two digits
                int originalI = i;
                for (; i < min((int) abbr.length(), i + 2) && abbr[i] >= '0' && abbr[i] <= '9'; i++) {
                }

                int digitCount = i - originalI;
                int subSLen = stoi(abbr.substr(originalI, digitCount));
                j += subSLen;
            }
        }

        return i == abbr.size() && j == word.size();
    }
};
