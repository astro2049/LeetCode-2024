#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        vector<pair<int, int>> cars;
        cars.reserve(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }
        sort(cars.begin(), cars.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });

        int fleets = 1;
        double tLeader = (float) (target - cars[0].first) / cars[0].second;
        for (int i = 1; i < cars.size(); i++) {
            if (cars[i].first + tLeader * cars[i].second >= target) {
                // Same fleet
                continue;
            } else {
                tLeader = (float) (target - cars[i].first) / cars[i].second;
                fleets++;
            }
        }

        return fleets;
    }
};
