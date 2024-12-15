#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MyCircularQueue {
public:
    int *data;
    int capacity;
    int front = -1;
    int rear = -1;
    int size = 0;

    MyCircularQueue(int k) : capacity(k) {
        data = new int[k];
    }

    ~MyCircularQueue() {
        delete[] data;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;

        if (size == 1) {
            front = rear;
        }

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[front];
    }

    int Rear() {
        return isEmpty() ? -1 : data[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
