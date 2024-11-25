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
    int directions[4][2] = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};

    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.emplace(0, j);
                visited[0][j] = true;
            }
            if (board[m - 1][j] == 'O') {
                q.emplace(m - 1, j);
                visited[m - 1][j] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.emplace(i, 0);
                visited[i][0] = true;
            }
            if (board[i][n - 1] == 'O') {
                q.emplace(i, n - 1);
                visited[i][n - 1] = true;
            }
        }

        while (!q.empty()) {
            auto ij = q.front();
            q.pop();
            int i = ij.first, j = ij.second;
            for (auto &direction: directions) {
                int ii = i + direction[0], jj = j + direction[1];
                if (ii < 0 || ii == m || jj < 0 || jj == n || board[ii][jj] == 'X' || visited[ii][jj]) {
                    continue;
                } else {
                    q.emplace(ii, jj);
                    visited[ii][jj] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
