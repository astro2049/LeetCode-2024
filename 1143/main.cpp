#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> maxCommons;
    string t1, t2;
    int m, n;

    int longestCommonSubsequence(string aT1, string aT2) {
        t1 = aT1, t2 = aT2;
        m = t1.length(), n = t2.length();

        maxCommons = vector<vector<int>>(m, vector<int>(n, -1));
        findBestMatch(0, 0);

        return maxCommons[0][0];
    }

    int findBestMatch(int i, int j) {
        if (i == m || j == n) {
            return 0;
        } else {
            if (maxCommons[i][j] == -1) {
                if (t1[i] == t2[j]) {
                    maxCommons[i][j] = 1 + findBestMatch(i + 1, j + 1);
                } else {
                    maxCommons[i][j] = max(findBestMatch(i + 1, j), findBestMatch(i, j + 1));
                }
            }
            return maxCommons[i][j];
        }
    }
};
