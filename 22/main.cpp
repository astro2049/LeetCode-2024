#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> parenthesis;
    int len;

    vector<string> generateParenthesis(int n) {
        len = n * 2;
        string s;
        generate(0, s, n, n, 0);
        return parenthesis;
    }

    void generate(int i, string &s, int lefts, int rights, int leftsInString) {
        if (i == len) {
            parenthesis.push_back(s);
            return;
        }
        bool leftOk = lefts > 0, rightOk = leftsInString > 0;
        if (leftOk) {
            s += "(";
            generate(i + 1, s, lefts - 1, rights, leftsInString + 1);
            s.pop_back();
        }
        if (rightOk) {
            s += ")";
            generate(i + 1, s, lefts, rights - 1, leftsInString - 1);
            s.pop_back();
        }
    }
};
