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
        int profit = 0;
        int i = 0, j = 0;
        for (; i < prices.size() && j < prices.size(); j++) {
            if (j == prices.size() - 1 || prices[j] > prices[j + 1]) {
                profit += prices[j] - prices[i];
                i = j + 1;
            }
        }
        return profit;
    }
};
