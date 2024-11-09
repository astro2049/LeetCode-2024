#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        int nonOverlaps = 0;
        for (int i = 0, j = 0; j < intervals.size();) {
            if (i == j) {
                nonOverlaps++;
                j++;
            } else {
                if (intervals[j][0] < intervals[i][1]) {
                    j++;
                } else {
                    i = j;
                }
            }
        }

        return intervals.size() - nonOverlaps;
    }
};
