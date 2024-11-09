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
        int money0 = 0, money1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int currentBest = max(money1, money0 + nums[i]);
            money0 = money1;
            money1 = currentBest;
        }
        return money1;
    }
};
