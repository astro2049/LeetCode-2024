#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<unsigned long long> combos(amount + 1);
        combos[0] = 1;

        for (auto &coin: coins) {
            for (int i = coin; i <= amount; i++) {
                combos[i] += combos[i - coin];
            }
        }

        return combos[amount];
    }
};
