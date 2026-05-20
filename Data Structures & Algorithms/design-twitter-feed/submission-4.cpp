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
        //insert self as I want top 10 feeds including this user and its followers
        followMap[userId].insert(userId);
        vector<int> ans;
        priority_queue<tuple<int, int, int, int>> maxHeap;
        //get all latest tweets from end of tweet feed, and use maxHeap to filter to 10
        for(int uId : followMap[userId]){
            if(tweetMap[uId].empty()){continue;}
            int ind = tweetMap[uId].size() - 1;
            int time = tweetMap[uId][ind].first;
            int tweetId = tweetMap[uId][ind].second;
            maxHeap.push({time, ind, tweetId, uId});
        }

        //filter top 10 feeds
        while(!maxHeap.empty() && ans.size() < 10){
            auto[time, ind, tweetId, uId] = maxHeap.top();
            maxHeap.pop();
            ans.push_back(tweetId);
            ind--;
            //now check if ind > 0, as we need to also push this in maxHeap, it may
            //become greater in near future
            if(ind >= 0){
                //get tweet and time for this user to push in max heap
                auto[time, tweetId] = tweetMap[uId][ind];
                maxHeap.push({time, ind, tweetId, uId});
            }
        }
        return ans;
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