#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> merged;

        int i = 0;
        for (; i < intervals.size(); i++) {
            auto ix = intervals[i];
            if (ix[1] < newInterval[0]) {
                merged.push_back(ix);
            } else {
                break;
            }
        }

        for (; i < intervals.size(); i++) {
            auto ix = intervals[i];
            if (ix[0] > newInterval[1]) {
                break;
            } else {
                newInterval[0] = min(newInterval[0], ix[0]);
                newInterval[1] = max(newInterval[1], ix[1]);
            }
        }
        merged.push_back(newInterval);

        for (; i < intervals.size(); i++) {
            auto ix = intervals[i];
            merged.push_back(ix);
        }

        return merged;
    }
};
