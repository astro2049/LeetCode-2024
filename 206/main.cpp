#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *previous = nullptr, *n = head;
        while (n) {
            ListNode *next = n->next;
            n->next = previous;
            previous = n;
            n = next;
        }
        return previous;
    }
};
