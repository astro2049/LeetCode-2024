#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1);
        for (int i = 1; i <= n; i++) {
            counts[i] = counts[i >> 1] + (i & 1);
        }
        return counts;
    }
};
