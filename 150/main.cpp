#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        unordered_set<string> operators = {"+", "-", "*", "/"};

        for (auto &token: tokens) {
            if (operators.find(token) != operators.end()) {
                int y = nums.top();
                nums.pop();
                int x = nums.top();
                nums.pop();
                if (token == "+") {
                    nums.push(x + y);
                } else if (token == "-") {
                    nums.push(x - y);
                } else if (token == "*") {
                    nums.push(x * y);
                } else {
                    nums.push(x / y);
                }
            } else {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};
