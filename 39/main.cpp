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

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> combo;
        choose(candidates, 0, combo, target);
        return combos;
    }

    void choose(vector<int> &candidates, int i, vector<int> &combo, int targetLeft) {
        if (targetLeft == 0) {
            combos.push_back(combo);
            return;
        }
        if (i == candidates.size() || targetLeft < 0) {
            return;
        }
        combo.push_back(candidates[i]);
        choose(candidates, i, combo, targetLeft - candidates[i]);
        combo.pop_back();
        choose(candidates, i + 1, combo, targetLeft);
    }
};
