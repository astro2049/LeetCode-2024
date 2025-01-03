#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *s = dummy, *f = s;
        for (int i = 0; i < n; i++) {
            f = f->next;
        }
        while (f->next) {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return dummy->next;
    }
};
