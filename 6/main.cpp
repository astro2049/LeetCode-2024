#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows = vector<string>(numRows);
        int currentRow = 0;
        int direction = 1;
        for (auto &c: s) {
            rows[currentRow] += c;
            currentRow += direction;
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction *= -1;
            }
        }

        string convertedS;
        for (auto &row: rows) {
            convertedS += row;
        }

        return convertedS;
    }
};
