#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int jump(vector<int> &nums) {
        int i = 0;
        int jumps = 0;
        while (i != nums.size() - 1) {
            jumps++;
            if (i + nums[i] >= nums.size() - 1) {
                break;
            } else {
                int bestPotential = -1, bestJ = -1;
                for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++) {
                    int potential = j + nums[j];
                    if (potential > bestPotential) {
                        bestPotential = potential;
                        bestJ = j;
                    }
                }
                i = bestJ;
            }
        }

        return jumps;
    }
};
