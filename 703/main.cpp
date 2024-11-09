#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>> firstKPq;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        sort(nums.begin(), nums.end(), greater<>());
        int i = 0;
        for (; i < nums.size() && i < k; i++) {
            firstKPq.push(nums[i]);
        }
        for (; i < nums.size(); i++) {
            if (nums[i] > firstKPq.top()) {
                firstKPq.push(nums[i]);
                firstKPq.pop();
            }
        }
    }

    int add(int val) {
        firstKPq.push(val);
        // Oops, queue overflow
        if (firstKPq.size() > k) {
            firstKPq.pop();
        }
        return firstKPq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
