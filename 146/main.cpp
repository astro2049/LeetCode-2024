#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> map;
    list<int> q;
    int capacity;

    LRUCache(int aCapacity) {
        capacity = aCapacity;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            updateKeyPriority(key);
            return map[key].second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key].second = value;
            updateKeyPriority(key);
        } else {
            q.push_back(key);
            map[key] = {prev(q.end()), value};
            if (map.size() > capacity) {
                map.erase(q.front());
                q.pop_front();
            }
        }
    }

    void updateKeyPriority(int key) {
        q.erase(map[key].first);
        q.push_back(key);
        map[key].first = prev(q.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
