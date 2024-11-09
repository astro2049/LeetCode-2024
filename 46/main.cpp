#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> combos;
    vector<int> nums;
    vector<bool> availables;
    vector<int> combo;

    vector<vector<int>> permute(vector<int> &aNums) {
        nums = aNums;
        availables.resize(nums.size(), true);

        choose(0);

        return combos;
    }

    void choose(int i) {
        if (i == nums.size()) {
            combos.push_back(combo);
            return;
        }
        for (int j = 0; j < nums.size(); j++) {
            if (availables[j]) {
                availables[j] = false;
                combo.push_back(nums[j]);
                choose(i + 1);
                combo.pop_back();
                availables[j] = true;
            }
        }
    }
};
