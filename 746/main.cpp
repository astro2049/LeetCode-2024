#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int cost0 = cost[0], cost1 = cost[1];
        int minCost;
        for (int i = 2; i < cost.size(); i++) {
            minCost = min(cost0, cost1) + cost[i];
            cost0 = cost1;
            cost1 = minCost;
        }
        minCost = min(cost0, cost1);
        return minCost;
    }
};
