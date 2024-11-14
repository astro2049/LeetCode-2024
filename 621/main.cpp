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
    int leastInterval(vector<char> &tasks, int n) {
        int occurrenceMap[26];
        for (auto &task: tasks) {
            occurrenceMap[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (occurrenceMap[i] != 0) {
                pq.push(occurrenceMap[i]);
            }
        }

        queue<pair<int, int>> cooldowns; // occurrence, next available time
        int time = 0;
        while (!pq.empty() || !cooldowns.empty()) {
            time++;
            if (!cooldowns.empty() && cooldowns.front().second == time) {
                pq.push(cooldowns.front().first);
                cooldowns.pop();
            }
            if (pq.empty()) {
                continue;
            } else {
                auto occurrence = pq.top();
                pq.pop();
                occurrence--;
                if (occurrence > 0) {
                    cooldowns.emplace(occurrence, time + n + 1);
                }
            }
        }

        return time;
    }
};
