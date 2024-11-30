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

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int oriColor = image[sr][sc];
        if (oriColor == color) {
            return image;
        }
        queue<pair<int, int>> q;

        q.emplace(sr, sc);
        image[sr][sc] = color;
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int i = cell.first, j = cell.second;
            for (auto &direction: directions) {
                int ii = i + direction[0], jj = j + direction[1];
                if (ii < 0 || ii == m || jj < 0 || jj == n || image[ii][jj] != oriColor) {
                    continue;
                }
                q.emplace(ii, jj);
                image[ii][jj] = color;
            }
        }

        return image;
    }
};
