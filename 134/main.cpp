#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
            sum += gas[i];
        }
        if (sum < 0) {
            return -1;
        }

        sum = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i];
            if (sum < 0) {
                res = i + 1;
                sum = 0;
            }
        }

        return res;
    }
};
