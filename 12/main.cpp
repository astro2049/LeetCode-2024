#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    char letters[4][2] = {
            {'I', 'V'},
            {'X', 'L'},
            {'C', 'D'},
            {'M', '_'},
    };

    string intToRoman(int num) {
        string s = to_string(num);
        string romanNum;
        for (int i = 0; i < s.length(); i++) {
            int x = s[i] - '0', digit = s.length() - 1 - i;
            if (x == 4) {
                romanNum += letters[digit][0];
                romanNum += letters[digit][1];
            } else if (x == 9) {
                romanNum += letters[digit][0];
                romanNum += letters[digit + 1][0];
            } else {
                if (x >= 5) {
                    romanNum += letters[digit][1];
                    x -= 5;
                }
                for (int j = 0; j < x; j++) {
                    romanNum += letters[digit][0];
                }
            }
        }

        return romanNum;
    }
};
