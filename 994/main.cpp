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
    int orangesRotting(vector<vector<int>> &grid) {
        int freshOranges = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }

        int directions[4][2] = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};

        int minute = 0;
        while (freshOranges != 0 && !q.empty()) {
            minute++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto cell = q.front();
                q.pop();
                for (auto &direction: directions) {
                    int ii = cell.first + direction[0], jj = cell.second + direction[1];
                    if (ii < 0 || ii == m || jj < 0 || jj == n || grid[ii][jj] != 1) {
                        continue;
                    }
                    grid[ii][jj] = 2;
                    freshOranges--;
                    q.emplace(ii, jj);
                }
            }
        }

        return freshOranges == 0 ? minute : -1;
    }
};
