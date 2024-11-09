#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (auto &num: nums) {
            map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for (auto &pair: map) {
            int num = pair.first;
            if (q.size() < k) {
                q.emplace(map[num], num);
            } else if (map[num] > q.top().first) {
                q.emplace(map[num], num);
                q.pop();
            }
        }

        vector<int> kEles;
        for (int i = 0; i < k; i++) {
            kEles.push_back(q.top().second);
            q.pop();
        }

        return kEles;
    }
};
