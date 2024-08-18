class Twitter {
private:
    vector<pair<int, int>> posts;
    unordered_map<int, unordered_set<int>> followMp;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        int count = 10;
        vector<int> tweets;
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) break;
            int currUser = posts[i].first;
            int currTweet = posts[i].second;
            unordered_set<int> followSet = followMp[userId];
            if (followSet.find(currUser) != followSet.end() || currUser == userId) {
                tweets.push_back(currTweet);
                count--;
            }
        }
        return tweets;
    }
    void follow(int followerId, int followeeId) {
        followMp[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        followMp[followerId].erase(followeeId);
    }
};