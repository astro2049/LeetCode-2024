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
    vector<vector<int>> combos;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combo;
        choose(0, combo, 0, candidates, target);

        return combos;
    }

    void choose(int i, vector<int> &combo, int sum, vector<int> &candidates, int target) {
        if (i == candidates.size()) {
            if (sum == target) {
                combos.push_back(combo);
            }
            return;
        } else if (sum > target) {
            return;
        } else {
            combo.push_back(candidates[i]);
            choose(i + 1, combo, sum + candidates[i], candidates, target);
            combo.pop_back();
            i++;
            while (i < candidates.size() && candidates[i - 1] == candidates[i]) {
                i++;
            }
            choose(i, combo, sum, candidates, target);
        }
    }
};
