#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (auto &time: times) {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> toExplores;
        unordered_set<int> visited;

        int time = 0;
        toExplores.emplace(0, k);
        while (!toExplores.empty()) {
            auto tn1 = toExplores.top();
            toExplores.pop();
            int t = tn1.first, n1 = tn1.second;
            if (visited.find(n1) != visited.end()) {
                continue;
            }
            visited.insert(n1);
            time = t;

            if (edges.find(n1) == edges.end()) {
                continue;
            }
            for (auto &next: edges[n1]) {
                int n2 = next.first, w = next.second;
                if (visited.find(n2) != visited.end()) {
                    continue;
                }
                toExplores.emplace(t + w, n2);
            }
        }

        return visited.size() == n ? time : -1;
    }
};
