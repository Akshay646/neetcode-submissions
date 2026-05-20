class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        vector<int> feeds;
        vector<pair<int, int>> allFeeds;
        for(auto followerId : followMap[userId]){
            for(auto tweet : tweetMap[followerId]){
                allFeeds.push_back({tweet.first, tweet.second});
            }
        }
        //sort descendingly to get latest feeds
        sort(allFeeds.begin(), allFeeds.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        //now get to 10 feeds. careful if overall feeds are < 10
        int allFeedSize = allFeeds.size();
        for(int i = 0; i < min(10, allFeedSize); i++){
            feeds.push_back(allFeeds[i].second);
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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