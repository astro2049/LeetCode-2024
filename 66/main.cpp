#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        digits.back()++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            if (digits[i] == 10) {
                digits[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
