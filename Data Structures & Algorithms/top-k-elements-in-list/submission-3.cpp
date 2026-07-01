class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto p : mp){
            bucket[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        int n = bucket.size();
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < bucket[i].size() && ans.size() < k; j++){
                ans.push_back(bucket[i][j]);
            }
        }
        return ans;
    }
};
