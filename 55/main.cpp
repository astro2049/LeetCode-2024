#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                return i == nums.size() - 1;
            }
            int maxFarRight = -1, bestJ = -1;
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++) {
                int farRight = j + nums[j];
                if (farRight > maxFarRight) {
                    maxFarRight = farRight;
                    bestJ = j;
                }
            }
            i = bestJ;
        }
        return true;
    }
};
