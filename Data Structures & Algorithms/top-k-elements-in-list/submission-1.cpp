class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> freq;
        vector<int> result;

        for(int i : nums)
        {
            freq[i]++;
        }

        //bucket{index=frequency, element=element from freq}
        //elements having same frequency will be store at that index
        for(auto pair : freq)
        {
           bucket[pair.second].push_back(pair.first);
        }

        //as we know, max elements would be at last as we always
        //store elements at their frequency
        for(int i = bucket.size() - 1; i >= 0; i--)
        {
            for(int j : bucket[i])
            {
                if(k == result.size()){return result;}
                result.push_back(j);
            }
        }

        return result;
    }
};
