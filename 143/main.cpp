#include <iostream>

using namespace std;

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
    void reorderList(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *previous = nullptr, *n = slow->next;
        slow->next = nullptr;
        while (n) {
            ListNode *next = n->next;
            n->next = previous;
            previous = n;
            n = next;
        }

        ListNode *l1 = head, *l2 = previous;
        while (l2) {
            ListNode *l1Next = l1->next;
            ListNode *l2Next = l2->next;

            l1->next = l2;
            l2->next = l1Next;

            l1 = l1Next;
            l2 = l2Next;
        }
    }
};
