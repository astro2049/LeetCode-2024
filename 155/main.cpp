#include <iostream>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MinStack {
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top()) {
            minStk.push(val);
        }
    }

    void pop() {
        int val = stk.top();
        stk.pop();
        if (val == minStk.top()) {
            minStk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */