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
    vector<vector<int>> subsets;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<int> subset;
        choose(0, nums, subset);
        return subsets;
    }

    void choose(int i, vector<int> &nums, vector<int> &subset) {
        if (i == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        choose(i + 1, nums, subset);
        subset.pop_back();

        i++;
        while (i < nums.size() && nums[i - 1] == nums[i]) {
            i++;
        }
        choose(i, nums, subset);
    }
};
