#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class SparseVector {
public:
    unordered_map<int, int> iv; // index, num

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                iv[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec) {
        int sum = 0;
        for (const auto &[i, num]: iv) {
            if (vec.iv.find(i) != vec.iv.end()) {
                sum += iv[i] * vec.iv[i];
            }
        }

        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);