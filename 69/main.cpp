#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int i = 0, j = x;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (mid <= x / mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return j;
    }
};
