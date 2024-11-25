#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (x >= 0) {
            for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
                swap(s[i], s[j]);
            }

            string maxx = to_string(INT_MAX);
            if (s.length() < maxx.length()) {
                return stoi(s);
            } else {
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] < maxx[i]) {
                        break;
                    } else if (s[i] > maxx[i]) {
                        return 0;
                    }
                }
                return stoi(s);
            }
        } else {
            for (int i = 1, j = s.length() - 1; i < j; i++, j--) {
                swap(s[i], s[j]);
            }

            string minn = to_string(INT_MIN);
            if (s.length() < minn.length()) {
                return stoi(s);
            } else {
                for (int i = 1; i < s.length(); i++) {
                    if (s[i] < minn[i]) {
                        break;
                    } else if (s[i] > minn[i]) {
                        return 0;
                    }
                }
                return stoi(s);
            }
        }
    }
};
