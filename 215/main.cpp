#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        int i = 0;
        for (; i < k; i++) {
            pq.push(nums[i]);
        }

        for (; i < nums.size(); i++) {
            if (nums[i] > pq.top()) {
                pq.push(nums[i]);
                pq.pop();
            }
        }

        return pq.top();
    }
};
