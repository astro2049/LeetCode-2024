#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        return max(robStraight(0, nums.size() - 2, nums), robStraight(1, nums.size() - 1, nums));
    }

    int robStraight(int start, int end, vector<int> &nums) {
        int money0 = 0, money1 = nums[start];
        for (int i = start + 1; i <= end; i++) {
            int money = max(money0 + nums[i], money1);
            money0 = money1;
            money1 = money;
        }
        return max(money0, money1);
    }
};
