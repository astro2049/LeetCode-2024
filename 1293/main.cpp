#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int shortestPath(vector<vector<int>> &grid, int kBudget) {
        int m = grid.size(), n = grid[0].size();
        if (kBudget >= m + n - 3) {
            return m + n - 2;
        }

        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, kBudget);
        unordered_map<int, unordered_map<int, unordered_set<int>>> visited;
        visited[0][0].insert(kBudget);
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y, k] = q.front();
                q.pop();
                if (x == m - 1 && y == n - 1) {
                    return steps - 1;
                }
                for (auto &direction: directions) {
                    int xx = x + direction[0], yy = y + direction[1];
                    if (xx < 0 || xx == m || yy < 0 || yy == n || visited[xx][yy].find(k) != visited[xx][yy].end()) {
                        continue;
                    }
                    if (grid[xx][yy] == 1) {
                        if (k == 0) {
                            continue;
                        } else {
                            q.emplace(xx, yy, k - 1);
                            visited[xx][yy].insert(k - 1);
                        }
                    } else {
                        q.emplace(xx, yy, k);
                        visited[xx][yy].insert(k);
                    }
                }
            }
        }

        return -1;
    }
};
