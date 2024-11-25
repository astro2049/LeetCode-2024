#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        } else if (n == 0) {
            return 1;
        } else {
            n *= -1;
        }
        return ponPon(x, n);
    }

    double ponPon(double x, int n) {
        if (n == -1) {
            return x;
        }
        double res = ponPon(x, n / 2);
        res *= res;
        if (n % 2 == -1) {
            res *= x;
        }
        return res;
    }
};
