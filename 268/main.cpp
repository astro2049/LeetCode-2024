#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            n ^= nums[i] ^ i;
        }
        return n;
    }
};
