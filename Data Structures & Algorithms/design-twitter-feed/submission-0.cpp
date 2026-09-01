class Twitter {
    unordered_map<int, vector<pair<int,int>>> users_tweets;
    unordered_map<int, unordered_set<int>> users_followers;

public:
    inline static int count = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        users_tweets[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        vector<pair<int,int>> temp;

        temp = users_tweets[userId];

        if (users_followers.count(userId)) {
            for (auto it : users_followers[userId]) {
                vector<pair<int,int>> t = users_tweets[it];
                temp.insert(temp.end(), t.begin(), t.end());
            }
        }

        sort(temp.begin(), temp.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.first > b.first;
            }
        );

        int n = temp.size();

        for (int i = 0; i < min(n, 10); i++) {
            res.push_back(temp[i].second);
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        users_followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        users_followers[followerId].erase(followeeId);
    }
};