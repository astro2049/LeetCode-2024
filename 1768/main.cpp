#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int len1 = min(word1.length(), word2.length());
        string s;
        while (i < len1) {
            s += word1[i];
            s += word2[i];
            i++;
        }
        while (i < word1.length()) {
            s += word1[i];
            i++;
        }
        while (i < word2.length()) {
            s += word2[i];
            i++;
        }
        return s;
    }
};
