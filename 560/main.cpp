#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        vector<int> prefixSums(nums.size() + 1);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefixSums[i + 1] = sum;
        }

        int count = 0;
        for (int i = 1; i < prefixSums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (prefixSums[i] - prefixSums[j] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
