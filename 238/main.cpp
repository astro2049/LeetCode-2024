#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int product = 1;
        vector<int> pps(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pps[i] = product;
            product *= nums[i];
            if (product == 0) {
                break;
            }
        }

        product = 1;
        vector<int> sps(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            sps[i] = product;
            product *= nums[i];
            if (product == 0) {
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = pps[i] * sps[i];
        }

        return nums;
    }
};
