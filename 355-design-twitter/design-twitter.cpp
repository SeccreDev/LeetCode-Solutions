class Twitter
{
    private:
        int timeStamp;

        unordered_map<int, vector<pair<int, int>>> tweets;
        unordered_map<int, unordered_set<int>> follows;

    public:
        Twitter()
        {
            timeStamp = 0;
        }

        void postTweet(int userId, int tweetId)
        {
            tweets[userId].emplace_back(timeStamp++, tweetId);
        }

        vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int, int>> maxHeap;
            follows[userId].insert(userId);  // Ensure user sees their own tweets

            for (int followeeId : follows[userId])
            {
                const auto& userTweets = tweets[followeeId];
                for (const auto& t : userTweets) {
                    maxHeap.push(t);
                }
            }

            vector<int> result;
            int count = 0;
            while (!maxHeap.empty() && count < 10)
            {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
                count++;
            }

            return result;
        }

        void follow(int followerId, int followeeId)
        {
            if (followerId == followeeId) return;
            follows[followerId].insert(followeeId);
        }

        void unfollow(int followerId, int followeeId)
        {
            if (followerId == followeeId) return;
            follows[followerId].erase(followeeId);
        }
};