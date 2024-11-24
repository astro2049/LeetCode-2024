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
    vector<unordered_map<int, int>> memo;
    vector<int> nums;
    int target;

    int findTargetSumWays(vector<int> &aNums, int aTarget) {
        nums = aNums, target = aTarget;
        memo.resize(nums.size());

        return choose(0, 0);
    }

    int choose(int i, int sum) {
        if (i == nums.size()) {
            if (sum == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (memo[i].find(sum) == memo[i].end()) {
                memo[i][sum] = choose(i + 1, sum + nums[i]) + choose(i + 1, sum - nums[i]);
            }
            return memo[i][sum];
        }
    }
};
