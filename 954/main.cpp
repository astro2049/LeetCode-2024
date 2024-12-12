#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        auto compare = [](const auto &a, const auto &b) {
            return abs(a) > abs(b);
        };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        for (auto &num: arr) {
            pq.push(num);
        }

        unordered_map<int, int> booked;
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if (booked[x] > 0) {
                booked[x]--;
            } else {
                booked[x * 2]++;
            }
        }

        for (auto &pair: booked) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
    }
};
