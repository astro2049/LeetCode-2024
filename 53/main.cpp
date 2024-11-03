#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int &num: nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};
