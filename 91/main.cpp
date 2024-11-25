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
    int numDecodings(string s) {
        unordered_set<string> nums;
        for (int i = 1; i <= 26; i++) {
            nums.insert(to_string(i));
        }

        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            int j = i - 1;
            if (nums.find(s.substr(j, 1)) != nums.end()) {
                dp[i] += dp[j];
            }
            int k = i - 2;
            if (k >= 0 && nums.find(s.substr(k, 2)) != nums.end()) {
                dp[i] += dp[k];
            }
            if (dp[i] == 0) {
                return 0;
            }
        }

        return dp.back();
    }
};
