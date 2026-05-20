class Solution {
public:
       
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> _groupAnagrams;
        unordered_map<string, vector<string>> result;
        for(int i = 0; i < strs.size(); i++)
        {
            vector<int> freq(26, 0);
            string freqStr = "";
            for(int j = 0; j < strs[i].size(); j++)
            {
                freq[strs[i][j] - 'a']++;
            }
            //creating frequency string as a key
            for(int j = 0; j < freq.size(); j++)
            {
                freqStr += to_string(freq[j]) + '#';
            }
            result[freqStr].push_back(strs[i]);
        }

        for(auto pair : result)
        {
            _groupAnagrams.push_back(pair.second);
        }
        return _groupAnagrams;
    }
};
