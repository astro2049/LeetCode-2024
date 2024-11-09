#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int maxCapacity = -1;

        while (i < j) {
            int capacity = (j - i) * min(height[i], height[j]);
            maxCapacity = max(maxCapacity, capacity);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxCapacity;
    }
};
