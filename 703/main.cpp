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
    priority_queue<int, vector<int>, greater<>> firstKMinus1Pq;
    priority_queue<int> fromKPq;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 0; i < k - 1; i++) {
            firstKMinus1Pq.push(nums[i]);
        }
        for (int i = k - 1; i < nums.size(); i++) {
            fromKPq.push(nums[i]);
        }
    }

    int add(int val) {
        firstKMinus1Pq.push(val);
        // Oops, queue overflow
        if (firstKMinus1Pq.size() > k - 1) {
            fromKPq.push(firstKMinus1Pq.top());
            firstKMinus1Pq.pop();
        }
        return fromKPq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
