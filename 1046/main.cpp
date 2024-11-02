#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> stonesQ;
        for (auto &stone: stones) {
            stonesQ.push(stone);
        }
        while (!stonesQ.empty() && stonesQ.size() != 1) {
            int y = stonesQ.top();
            stonesQ.pop();
            int x = stonesQ.top();
            stonesQ.pop();
            if (x == y) {
                continue;
            } else {
                stonesQ.push(y - x);
            }
        }
        return stonesQ.empty() ? 0 : stonesQ.top();
    }
};
