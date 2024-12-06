#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }

    vector<int> mergeTwoArrays(vector<int> &nums1, vector<int> &nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> mergeArray(size1 + size2);
        int i = 0, j = 0;
        for (; i < size1 && j < size2;) {
            if (nums1[i] < nums2[j]) {
                mergeArray[i + j] = nums1[i];
                i++;
            } else {
                mergeArray[i + j] = nums2[j];
                j++;
            }
        }

        while (i < size1) {
            mergeArray[i + j] = nums1[i];
            i++;
        }
        while (j < size2) {
            mergeArray[i + j] = nums2[j];
            j++;
        }

        return mergeArray;
    }

    vector<int> mergeSort(int i, int j, vector<int> &nums) {
        if (i == j) {
            return {nums[i]};
        }

        int mid = (i + j) / 2;
        auto mergedLeftArray = mergeSort(i, mid, nums);
        auto mergedRightArray = mergeSort(mid + 1, j, nums);

        return mergeTwoArrays(mergedLeftArray, mergedRightArray);
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 4, 5};
    auto sortedNums = Solution().sortArray(nums);

    for (int &sortedNum: sortedNums) {
        cout << sortedNum << " ";
    }

    return 0;
}
