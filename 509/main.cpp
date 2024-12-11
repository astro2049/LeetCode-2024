#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        int last2 = 0, last1 = 1;
        int current;
        for (int i = 2; i <= n; i++) {
            current = last2 + last1;
            last2 = last1;
            last1 = current;
        }

        return current;
    }
};
