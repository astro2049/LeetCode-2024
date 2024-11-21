#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

auto compare = [](const auto &a, const auto &b) {
    return a.second > b.second;
};

class Twitter {
public:
    unordered_map<int, unordered_set<int>> followings; // followerId, followeeId
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // pair - tweetId, timestamp

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp);
        timestamp++;
    }

    void addTweetToPq(priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> &pq, int tweetId,
                      int timestamp) {
        pq.emplace(tweetId, timestamp);
        if (pq.size() > 10) {
            pq.pop();
        }
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(
                compare); // pair - tweetId, timestamp
        for (int i = max(0, (int) tweets[userId].size() - 10); i < tweets[userId].size(); i++) {
            auto &tweet = tweets[userId][i];
            addTweetToPq(pq, tweet.first, tweet.second);
        }
        for (auto &followeeId: followings[userId]) {
            for (int i = max(0, (int) tweets[followeeId].size() - 10); i < tweets[followeeId].size(); i++) {
                auto &tweet = tweets[followeeId][i];
                addTweetToPq(pq, tweet.first, tweet.second);
            }
        }

        vector<int> feed(pq.size());
        for (int i = feed.size() - 1; i >= 0; i--) {
            feed[i] = pq.top().first;
            pq.pop();
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
