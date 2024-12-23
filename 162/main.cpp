#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (mid == 0 || nums[mid - 1] < nums[mid]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return -1;
    }
};
