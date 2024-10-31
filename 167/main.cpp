#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j;) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};
