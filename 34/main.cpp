#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }

    int findFirst(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        int res = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] == target) {
                res = mid;
                j = mid - 1;
            } else {
                j = mid - 1;
            }
        }

        return res;
    }

    int findLast(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        int res = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] == target) {
                res = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return res;
    }
};
