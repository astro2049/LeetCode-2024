#include <iostream>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto &c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                } else {
                    if (c == ')') {
                        if (stack.top() == '(') {
                            stack.pop();
                        } else {
                            return false;
                        }
                    } else if (c == ']') {
                        if (stack.top() == '[') {
                            stack.pop();
                        } else {
                            return false;
                        }
                    } else {
                        if (stack.top() == '{') {
                            stack.pop();
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        return stack.empty();
    }
};
