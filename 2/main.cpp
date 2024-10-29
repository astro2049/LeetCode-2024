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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int len1 = listLength(l1), len2 = listLength(l2);
        if (len1 < len2) {
            return addShortLongNumbers(l1, l2);
        } else {
            return addShortLongNumbers(l2, l1);
        }
    }

    ListNode *addShortLongNumbers(ListNode *l1, ListNode *l2) {
        ListNode *n1 = l1, *n2 = l2;

        while (n1) {
            n2->val += n1->val;
            if (n2->val >= 10) {
                n2->val -= 10;
                if (n2->next) {
                    n2->next->val += 1;
                } else {
                    n2->next = new ListNode(1);
                }
            }
            n1 = n1->next;
            n2 = n2->next;
        }

        while (n2) {
            if (n2->val >= 10) {
                n2->val -= 10;
                if (n2->next) {
                    n2->next->val += 1;
                } else {
                    n2->next = new ListNode(1);
                }
            } else {
                break;
            }
            n2 = n2->next;
        }

        return l2;
    }

    int listLength(ListNode *n) {
        int len = 0;
        while (n) {
            len++;
            n = n->next;
        }
        return len;
    }
};
