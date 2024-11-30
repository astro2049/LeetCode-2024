#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> stack;
        int maxArea = -1;
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.top()] > heights[i]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = !stack.empty() ? i - stack.top() - 1 : i;
                maxArea = max(maxArea, width * height);
            }

            stack.push(i);
        }

        while (!stack.empty()) {
            int height = heights[stack.top()];
            stack.pop();
            int width = !stack.empty() ? heights.size() - stack.top() - 1 : heights.size();
            maxArea = max(maxArea, width * height);
        }

        return maxArea;
    }
};
