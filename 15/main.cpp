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
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> combos;
        for (int i = 0; i < nums.size() - 2;) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    combos.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
            i++;
            while (i < nums.size() - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
        }

        return combos;
    }
};
