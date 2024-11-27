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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head), *n = dummy;
        for (int i = 0; i < left - 1; i++) {
            n = n->next;
        }

        ListNode *prev = n, *current = n->next;
        for (int i = left; i <= right; i++) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        n->next->next = current;
        n->next = prev;

        return dummy->next;
    }
};
