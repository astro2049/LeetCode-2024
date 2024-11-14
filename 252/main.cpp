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
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] <= intervals[i][0]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
