#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for (auto &num: nums) {
            set.insert(num);
        }

        int maxLen = 0;
        unordered_set<int> visited;
        for (auto &x: set) {
            if (visited.find(x) != visited.end()) {
                continue;
            }

            int len = 1;
            visited.insert(x);

            for (int a = x - 1; set.find(a) != set.end(); a--) {
                len++;
                visited.insert(a);
            }
            for (int a = x + 1; set.find(a) != set.end(); a++) {
                len++;
                visited.insert(a);
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
