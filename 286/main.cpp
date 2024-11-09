#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        queue<pair<int, int>> q;
        int m = rooms.size(), n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }

        vector<vector<int>> directions = {{1,  0},
                                          {-1, 0},
                                          {0,  1},
                                          {0,  -1}};
        int dis = 0;
        while (!q.empty()) {
            int count = q.size();
            dis++;
            for (int k = 0; k < count; k++) {
                auto room = q.front();
                q.pop();
                for (auto &direction: directions) {
                    int ii = room.first + direction[0], jj = room.second + direction[1];
                    if (ii < 0 || ii == m || jj < 0 || jj == n) {
                        continue;
                    }
                    auto &neighbor = rooms[ii][jj];
                    if (neighbor == -1 || neighbor != INT_MAX || neighbor == 0) {
                        continue;
                    }
                    neighbor = dis;
                    q.emplace(ii, jj);
                }
            }
        }
    }
};
