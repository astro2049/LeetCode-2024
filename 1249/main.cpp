#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> lefts;
        unordered_set<int> bracketIs;

        for (int i = 0; i < s.length(); i++) {
            char &c = s[i];
            if (c == '(') {
                lefts.push(i);
            } else if (c == ')') {
                if (!lefts.empty()) {
                    bracketIs.insert(lefts.top());
                    lefts.pop();
                    bracketIs.insert(i);
                }
            }
        }

        string ss;
        for (int i = 0; i < s.length(); i++) {
            char &c = s[i];
            if (c == '(' || c == ')') {
                if (bracketIs.find(i) != bracketIs.end()) {
                    ss += c;
                }
            } else {
                ss += c;
            }
        }

        return ss;
    }
};
