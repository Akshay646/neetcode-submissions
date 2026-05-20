class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> simplifiedSet;
        unordered_map<int, int> freq;
        vector<int> result;

        for(int i : nums)
        {
            freq[i]++;
        }

        //simplification of map into vector of pairs for sorting
        for(auto pair : freq)
        {
            //As priority queueu by default maintain max heap
            //by first element, and we need to consider max frequency
            //so adding pair's first element as frequency followed by element
            simplifiedSet.push({pair.second, pair.first});
        }

        //storing max k elements
        while(!simplifiedSet.empty() && k > 0)
        {
            pair<int, int> pair = simplifiedSet.top();
            simplifiedSet.pop();
            result.push_back(pair.second);
            k--;
        }

        return result;
    }
};
