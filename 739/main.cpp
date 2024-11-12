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
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> downhillIs;

        vector<int> warmers(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!downhillIs.empty() && temperatures[i] > temperatures[downhillIs.top()]) {
                int k = downhillIs.top();
                downhillIs.pop();
                warmers[k] = i - k;
            }
            downhillIs.push(i);
        }

        return warmers;
    }
};
