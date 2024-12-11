#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i] > 0 ? nums[i] : -nums[i];

            if (nums[num - 1] < 0) {
                continue;
            }
            nums[num - 1] *= -1;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
