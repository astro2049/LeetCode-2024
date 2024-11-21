#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> cards;
        for (auto &card: hand) {
            cards[card]++;
        }

        int usedCards = 0;
        while (usedCards != hand.size()) {
            auto cardPair = cards.begin();
            int card = cardPair->first;
            for (int i = 0; i < groupSize; i++) {
                if (cardPair == cards.end() || card != cardPair->first) {
                    return false;
                } else {
                    usedCards++;
                    cardPair->second--;
                    if (cardPair->second == 0) {
                        cardPair++;
                        cards.erase(card);
                    } else {
                        cardPair++;
                    }
                    card++;
                }
            }
        }

        return true;
    }
};
