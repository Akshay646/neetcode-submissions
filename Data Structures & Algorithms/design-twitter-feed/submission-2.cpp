class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        vector<int> feeds;
        //<time, indOfElementFOrThatLst, userId, tweetId>
        priority_queue<tuple<int, int, int, int>> pq;

        //now since all tweets are inserted increasing in time, for each user,
        //the latest tweet would be at the end of each list. we consume them and
        //add it to max heap to collect latest 10. If we not get, we keep looking
        //further by traversing respective lists based on maxHeap

        for(int followerId : followMap[userId]){
            //if no tweets, the ind will become -1, avoid that
            if(tweetMap[followerId].empty()) continue;
            int ind = tweetMap[followerId].size() - 1;
            //fetch the last tweet of current list if tweet for given userId
            auto tweet = tweetMap[followerId][ind];
            pq.push({tweet.first, ind, followerId, tweet.second});
        }

        //now process max heap, if still < 10, traverse based on index
        while(!pq.empty() && feeds.size() < 10){
            auto [_time, _currInd, currUserId, tweetId] = pq.top();
            pq.pop(); //=> now top will have max time automaticaaly
            feeds.push_back(tweetId);

            //now we process tweets for current user by going to prev tweet
            //i.e. ind--, and add the tweet in maxheap, as it can be valid latest
            //if ind < 0 means, for current user, we have traversed all tweets
            //and so, max heap anyway will go to next max tweet it has at top
            _currInd--; //go to previous tweet for current user
            if(_currInd >= 0){
                //get the tweet
                auto tweet = tweetMap[currUserId][_currInd];
                //_currInd and currUserId stays same as we are actually looking
                //tweet for them only
                pq.push({tweet.first, _currInd, currUserId, tweet.second});
            }
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