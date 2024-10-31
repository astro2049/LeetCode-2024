#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;

        unordered_map<char, int> counts;
        int maxCount = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            counts[s[j]]++;
            maxCount = max(maxCount, counts[s[j]]);
            while (j - i + 1 - maxCount > k) {
                counts[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
