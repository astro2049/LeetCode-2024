#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> nums3(m + n);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums3[i + j] = nums1[i];
                i++;
            } else {
                nums3[i + j] = nums2[j];
                j++;
            }
        }
        while (i < m) {
            nums3[i + j] = nums1[i];
            i++;
        }
        while (j < n) {
            nums3[i + j] = nums2[j];
            j++;
        }
        nums1 = nums3;
    }
};
