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
    int directions[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        if (n == 1) {
            return 1;
        }

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 1;
        int count = 0;
        while (!q.empty()) {
            count++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto &direction: directions) {
                    int ii = i + direction[0], jj = j + direction[1];
                    if (ii < 0 || ii == n || jj < 0 || jj == n || grid[ii][jj] == 1) {
                        continue;
                    }
                    if (ii == n - 1 && jj == n - 1) {
                        return count + 1;
                    } else {
                        q.emplace(ii, jj);
                        grid[ii][jj] = 1;
                    }
                }
            }
        }

        return -1;
    }
};
