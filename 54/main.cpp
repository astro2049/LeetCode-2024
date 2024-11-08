#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size(), totalCount = m * n;
        vector<vector<bool>> visited(m, vector<bool>(n));
        int i = 0, j = 0;
        vector<int> eles;

        vector<vector<int>> directions = {{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}};
        int direction = 0;
        while (eles.size() != totalCount) {
            visited[i][j] = true;
            eles.push_back(matrix[i][j]);
            int ii = i + directions[direction][0], jj = j + directions[direction][1];
            if (ii < 0 || ii == m || jj < 0 || jj == n || visited[ii][jj]) {
                direction = (direction + 1) % 4;
            }
            i += directions[direction][0], j += directions[direction][1];
        }

        return eles;
    }
};
