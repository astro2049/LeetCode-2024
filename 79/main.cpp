#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<char>> board;
    int m, n;
    string word;
    vector<vector<bool>> visited;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool exist(vector<vector<char>> &aBoard, string aWord) {
        board = aBoard, word = aWord;
        m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = true;
                if (dfs(i, j, 0)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int x) {
        if (board[i][j] == word[x]) {
            if (x == word.length() - 1) {
                return true;
            } else {
                for (auto &direction: directions) {
                    int ii = i + direction[0], jj = j + direction[1];
                    if (ii < 0 || ii == m || jj < 0 || jj == n || visited[ii][jj]) {
                        continue;
                    } else {
                        visited[ii][jj] = true;
                        if (dfs(ii, jj, x + 1)) {
                            return true;
                        }
                        visited[ii][jj] = false;
                    }
                }
                return false;
            }
        } else {
            return false;
        }
    }
};
