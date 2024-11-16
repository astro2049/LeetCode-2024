#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occurred = {n};
        while (n != 1) {
            int newN = 0;
            while (n != 0) {
                int digit = n % 10;
                n /= 10;
                newN += digit * digit;
            }
            if (occurred.find(newN) != occurred.end()) {
                return false;
            } else {
                n = newN;
                occurred.insert(n);
            }
        }
        return true;
    }
};
