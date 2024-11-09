#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> cooldowns(n), holds(n), sells(n);
        holds[0] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            holds[i] = max(cooldowns[i - 1] - prices[i], holds[i - 1]);
            sells[i] = holds[i - 1] + prices[i];
            cooldowns[i] = max(sells[i - 1], cooldowns[i - 1]);
        }
        return max(sells.back(), cooldowns.back());
    }
};
