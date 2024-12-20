#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num), gs = s;
        sort(gs.begin(), gs.end(), greater<>());
        int i = 0;
        for (; i < s.length(); i++) {
            if (s[i] != gs[i]) {
                break;
            }
        }
        if (i == s.length()) {
            return num;
        }

        int maxValMinIndex = s.length() - 1;
        for (int j = maxValMinIndex - 1; j > i; j--) {
            if (s[j] > s[maxValMinIndex]) {
                maxValMinIndex = j;
            }
        }

        swap(s[i], s[maxValMinIndex]);
        return stoi(s);
    }
};
