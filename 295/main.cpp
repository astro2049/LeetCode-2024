#include <iostream>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> minPq;
    priority_queue<int> maxPq;

    MedianFinder() {

    }

    void addNum(int num) {
        minPq.push(num);

        if (!maxPq.empty() && minPq.top() < maxPq.top()) {
            maxPq.push(minPq.top());
            minPq.pop();
        }

        if (minPq.size() == maxPq.size() + 2) {
            maxPq.push(minPq.top());
            minPq.pop();
        } else if (minPq.size() < maxPq.size()) {
            minPq.push(maxPq.top());
            maxPq.pop();
        }
    }

    double findMedian() {
        if (minPq.size() != maxPq.size()) {
            return minPq.top();
        } else {
            return (minPq.top() + maxPq.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
