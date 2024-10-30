#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<bool>> visited;
    int m, n;
    int offsets[4][2] = {{1,  0},
                         {-1, 0},
                         {0,  1},
                         {0,  -1}};

    int numIslands(vector<vector<char>> &grid) {
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));

        int islandCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islandCount++;
                    traverseIsland(i, j, grid);
                }
            }
        }
        return islandCount;
    }

    void traverseIsland(int i, int j, vector<vector<char>> &grid) {
        visited[i][j] = true;
        for (auto offset: offsets) {
            int ii = i + offset[0], jj = j + offset[1];
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || grid[ii][jj] == '0' || visited[ii][jj]) {
                continue;
            }
            traverseIsland(ii, jj, grid);
        }
    }
};
