#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class City {
public:
    int num;
    int cost;
    int stop;

    City(int num, int cost, int stop) : num(num), cost(cost), stop(stop) {}
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> cities(n, vector<pair<int, int>>());
        for (auto &flight: flights) {
            cities[flight[0]].emplace_back(flight[1], flight[2]);
        }

        queue<City> q;
        // cost, city num, current stop num
        q.emplace(src, 0, 0);
        int cheapestPrice = INT_MAX;

        vector<vector<int>> minCosts(n, vector<int>(k + 2, INT_MAX));

        while (!q.empty()) {
            auto city = q.front();
            q.pop();
            for (auto &next: cities[city.num]) {
                int nextNum = next.first, nextCost = city.cost + next.second, nextStop = city.stop + 1;
                if (nextStop < n && nextStop <= k + 1) {
                    if (nextNum == dst) {
                        cheapestPrice = min(cheapestPrice, nextCost);
                    } else {
                        if (nextCost < minCosts[nextNum][nextStop]) {
                            minCosts[nextNum][nextStop] = nextCost;
                            q.emplace(nextNum, nextCost, nextStop);
                        }
                    }
                }
            }
        }

        return cheapestPrice != INT_MAX ? cheapestPrice : -1;
    }

};
