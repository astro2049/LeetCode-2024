#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int minSpeed;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (canFinish(piles, h, mid)) {
                minSpeed = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return minSpeed;
    }

    bool canFinish(vector<int> &piles, int timeBudget, int speed) {
        for (auto &pile: piles) {
            timeBudget -= pile % speed == 0 ? pile / speed : pile / speed + 1;
            if (timeBudget < 0) {
                return false;
            }
        }
        return true;
    }
};
