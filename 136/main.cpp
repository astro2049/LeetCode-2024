#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            n ^= nums[i];
        }
        return n;
    }
};
