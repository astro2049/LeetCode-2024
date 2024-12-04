#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        int len = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            len = min(len, (int) strs[i].length());
        }

        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] == c) {
                    continue;
                } else {
                    return prefix;
                }
            }
            prefix += c;
        }

        return prefix;
    }
};
