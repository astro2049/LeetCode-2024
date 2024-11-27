#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int trap(vector<int> &heights) {
        int i = 0, j = heights.size() - 1;
        int lMax = heights[i], rMax = heights[j];
        int water = 0;
        while (i < j) {
            if (lMax < rMax) {
                water += lMax - heights[i];
                i++;
                if (heights[i] > lMax) {
                    lMax = heights[i];
                }
            } else {
                water += rMax - heights[j];
                j--;
                if (heights[j] > rMax) {
                    rMax = heights[j];
                }
            }
        }

        return water;
    }
};
