class Solution {
public:
       
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> _groupAnagrams;
        unordered_map<string, vector<string>> result;
        for(int i = 0; i < strs.size(); i++)
        {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            result[sortedStr].push_back(strs[i]);
        }

        for(auto pair : result)
        {
            _groupAnagrams.push_back(pair.second);
        }
        return _groupAnagrams;
    }
};
