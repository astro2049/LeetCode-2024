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
        int maxEarn = 0;

        int i = 0, j = 0;
        for (; i < prices.size() && j < prices.size();) {
            if (prices[i] > prices[j]) {
                i = j;
            } else {
                int profit = prices[j] - prices[i];
                maxEarn = max(maxEarn, profit);
                j++;
            }
        }

        return maxEarn;
    }
};
