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
    int maxProduct(vector<int> &nums) {
        int res = *max_element(nums.begin(), nums.end());

        int maxProduct = 1, minProduct = 1;
        for (auto &x: nums) {
            if (x == 0) {
                maxProduct = 1, minProduct = 1;
                continue;
            }
            int temp = maxProduct;
            maxProduct = max({maxProduct * x, minProduct * x, x});
            minProduct = min({temp * x, minProduct * x, x});
            res = max(res, maxProduct);
        }

        return res;
    }
};
