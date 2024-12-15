#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int maxSum = INT_MIN, currMaxSum = 0, minSum = INT_MAX, currMinSum = 0, sum = 0;
        for (auto &num: nums) {
            currMaxSum += num;
            maxSum = max(maxSum, currMaxSum);
            if (currMaxSum < 0) {
                currMaxSum = 0;
            }

            sum += num;
            currMinSum += num;
            minSum = min(minSum, currMinSum);
            if (currMinSum > 0) {
                currMinSum = 0;
            }
        }

        return minSum == sum ? maxSum : max(maxSum, sum - minSum);
    }
};
