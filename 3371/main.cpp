#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int getLargestOutlier(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto &x: nums) {
            sum += x;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if ((sum - nums[i]) % 2 != 0) {
                continue;
            }
            int target = (sum - nums[i]) / 2;

            if (target == nums[i]) {
                if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                    return nums[i - 1];
                }
                if (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                    return nums[i + 1];
                }
            } else if (target < nums[i]) {
                int res = binarySearch(0, i - 1, target, nums);
                if (res) {
                    return nums[i];
                }
            } else {
                int res = binarySearch(i + 1, nums.size(), target, nums);
                if (res) {
                    return nums[i];
                }
            }
        }

        return -1;
    }

    bool binarySearch(int i, int j, int target, vector<int> &nums) {
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
