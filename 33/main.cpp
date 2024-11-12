#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;

        if (nums[0] <= nums.back()) {

        } else {
            i = 1;
            int minI;
            while (i <= j) {
                int mid = (i + j) / 2;
                if (nums[mid - 1] > nums[mid]) {
                    minI = mid;
                    break;
                } else if (nums[mid] >= nums[0]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }

            if (target >= nums[0]) {
                i = 0, j = minI - 1;
            } else {
                i = minI, j = nums.size() - 1;
            }
        }

        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
