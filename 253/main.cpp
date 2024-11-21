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
    int minMeetingRooms(vector<vector<int>> &intervals) {
        vector<int> starts(intervals.size()), ends(intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int maxOverlaps = 0;
        int overlaps = 0;

        for (int i = 0, j = 0; i < starts.size();) {
            if (starts[i] < ends[j]) {
                overlaps++;
                maxOverlaps = max(maxOverlaps, overlaps);
                i++;
            } else {
                overlaps--;
                j++;
            }
        }

        return maxOverlaps;
    }
};
