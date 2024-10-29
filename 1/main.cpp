#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> numIMap;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int y = target - x;
            if (numIMap.find(y) == numIMap.end()) {
                numIMap[x] = i;
            } else {
                return {i, numIMap[y]};
            }
        }
        return {};
    }
};
