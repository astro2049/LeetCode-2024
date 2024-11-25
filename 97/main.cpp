#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string s1, s2, s3;
    vector<vector<int>> memo;

    bool isInterleave(string aS1, string aS2, string aS3) {
        s1 = aS1, s2 = aS2, s3 = aS3;
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        memo.resize(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return choose(0, 0);
    }

    bool choose(int i, int j) {
        int k = i + j;
        if (k == s3.length()) {
            return i == s1.length() && j == s2.length();
        } else if (i == s1.length() && j == s2.length()) {
            return false;
        } else {
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
            memo[i][j] = false;
            if (i < s1.length() && s1[i] == s3[k]) {
                memo[i][j] = memo[i][j] || choose(i + 1, j);
            }
            if (j < s2.length() && s2[j] == s3[k]) {
                memo[i][j] = memo[i][j] || choose(i, j + 1);
            }
            return memo[i][j];
        }
    }
};
