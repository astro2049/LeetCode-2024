#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<bool> nums(9);
        for (int j = 0; j < 9; j++) {
            fill(nums.begin(), nums.end(), false);
            for (int i = 0; i < 9; i++) {
                auto &num = board[i][j];
                if (num == '.') {
                    continue;
                }
                if (nums[num - '1']) {
                    return false;
                } else {
                    nums[num - '1'] = true;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            fill(nums.begin(), nums.end(), false);
            for (int j = 0; j < 9; j++) {
                auto &num = board[i][j];
                if (num == '.') {
                    continue;
                }
                if (nums[num - '1']) {
                    return false;
                } else {
                    nums[num - '1'] = true;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                fill(nums.begin(), nums.end(), false);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        auto &num = board[i * 3 + k][j * 3 + l];
                        if (num == '.') {
                            continue;
                        }
                        if (nums[num - '1']) {
                            return false;
                        } else {
                            nums[num - '1'] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
