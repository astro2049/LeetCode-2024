#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow1 = 0;
        while (slow1 != slow) {
            slow1 = nums[slow1];
            slow = nums[slow];
        }

        return slow1;
    }
};
