#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> powerSet;

    vector<vector<int>> subsets(vector<int> &aNums) {
        nums = aNums;
        n = nums.size();

        generate(0, {});

        return powerSet;
    }

    void generate(int i, vector<int> currentSet) {
        if (i == n) {
            powerSet.push_back(currentSet);
            return;
        }
        generate(i + 1, currentSet);
        currentSet.push_back(nums[i]);
        generate(i + 1, currentSet);
    }
};
