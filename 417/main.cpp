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
    int m, n;
    vector<vector<bool>> pacificStreams, atlanticStreams;
    int directions[4][2] = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size(), n = heights[0].size();
        pacificStreams = vector<vector<bool>>(m, vector<bool>(n)), atlanticStreams = pacificStreams;

        markStreams(heights, 0, 0, pacificStreams);
        markStreams(heights, m - 1, n - 1, atlanticStreams);

        vector<vector<int>> cells;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificStreams[i][j] && atlanticStreams[i][j]) {
                    cells.push_back({i, j});
                }
            }
        }
        return cells;
    }

    void markStreams(vector<vector<int>> &heights, int startRow, int startCol, vector<vector<bool>> &connected) {
        queue<pair<int, int>> q;
        q.emplace(startRow, startCol);
        connected[startRow][startCol] = true;
        for (int j = 0; j < n; j++) {
            if (j == startCol) {
                continue;
            }
            q.emplace(startRow, j);
            connected[startRow][j] = true;
        }
        for (int i = 0; i < m; i++) {
            if (i == startRow) {
                continue;
            }
            q.emplace(i, startCol);
            connected[i][startCol] = true;
        }
        while (!q.empty()) {
            auto ij = q.front();
            q.pop();
            int i = ij.first, j = ij.second;
            for (auto &direction: directions) {
                int ii = i + direction[0], jj = j + direction[1];
                if (ii < 0 || ii == m || jj < 0 || jj == n || connected[ii][jj] || heights[ii][jj] < heights[i][j]) {
                    continue;
                }
                q.emplace(ii, jj);
                connected[ii][jj] = true;
            }
        }
    }
};
