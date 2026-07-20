class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;//{freq, number}
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i : nums){
            mp[i]++;
        }
        for(const auto& [key, val] : mp){
            pq.push({val, key});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
