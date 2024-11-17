#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        const auto &stampVs = m[key];
        int i = 0, j = stampVs.size() - 1;
        int targetI = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            const auto &entry = stampVs[mid];
            if (entry.first <= timestamp) {
                targetI = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return targetI != -1 ? stampVs[targetI].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
