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
    int maxArea = 0;
    vector<vector<int>> grid;
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>> &aGrid) {
        grid = aGrid;
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = islandArea(i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    int islandArea(int startI, int startJ) {
        int area = 0;

        queue<pair<int, int>> cells;
        cells.emplace(startI, startJ);
        visited[startI][startJ] = true;
        while (!cells.empty()) {
            auto cell = cells.front();
            cells.pop();
            int i = cell.first, j = cell.second;
            area++;

            for (auto &offset: offsets) {
                int ii = i + offset[0], jj = j + offset[1];
                if (ii < 0 || ii == m || jj < 0 || jj == n || grid[ii][jj] == 0 || visited[ii][jj]) {
                    continue;
                } else {
                    cells.emplace(ii, jj);
                    visited[ii][jj] = true;
                }
            }
        }

        return area;
    }
};
