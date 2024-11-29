#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> map;
        for (auto &c: s) {
            map[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto &pair: map) {
            pq.emplace(pair.second, pair.first);
        }

        string reS;
        pair<int, char> cooldownChar = {-1, '<'};
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            reS += top.second;
            top.first--;

            if (cooldownChar.first != -1) {
                pq.push(cooldownChar);
                cooldownChar.first = -1;
            }

            if (top.first > 0) {
                cooldownChar = top;
            }
        }
        return reS.length() == s.length() ? reS : "";
    }
};
