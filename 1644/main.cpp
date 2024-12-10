#include <iostream>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {

    }

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            transferElements();
        }

        int x = stack2.top();
        stack2.pop();
        return x;
    }

    int peek() {
        if (stack2.empty()) {
            transferElements();
        }

        return stack2.top();
    }

    void transferElements() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
