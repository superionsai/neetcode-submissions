class Twitter {
public:
    int timeStamp;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
        if (tweets[userId].size() > 10)
            tweets[userId].erase(tweets[userId].begin());
    }

    vector<int> getNewsFeed(int userId) {
        follows[userId].insert(userId);

        priority_queue<vector<int>> pq;

        for (int f : follows[userId]) {
            if (!tweets.count(f)) continue;
            int idx = tweets[f].size() - 1;
            auto &p = tweets[f][idx];
            pq.push({p.first, p.second, f, idx - 1});
        }

        vector<int> res;

        while (!pq.empty() && res.size() < 10) {
            auto t = pq.top(); 
            pq.pop();
            res.push_back(t[1]);

            int u = t[2];
            int idx = t[3];

            if (idx >= 0) {
                auto &p = tweets[u][idx];
                pq.push({p.first, p.second, u, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            follows[followerId].erase(followeeId);
    }
};
