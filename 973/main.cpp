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
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < points.size(); i++) {
            auto &point = points[i];
            pq.emplace(point[0] * point[0] + point[1] * point[1], i);
        }

        vector<vector<int>> minKs;
        for (int i = 0; i < k; i++) {
            minKs.push_back(points[pq.top().second]);
            pq.pop();
        }
        return minKs;
    }
};
