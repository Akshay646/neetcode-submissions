class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(26), freq2(26);

        for(int i = 0; i < s.size(); i++)
        {
            freq1[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            freq2[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(freq1[i] != freq2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> _groupAnagrams;
        for(int i = 0; i < strs.size(); i++)
        {
            vector<string> tmpAnagrams;
            string tmpStr = strs[i];
            if(tmpStr != "$")
            {
            for(int j = i; j < strs.size(); j++)
            {
                if(strs[j] != "$" && isAnagram(tmpStr, strs[j]))
                {
                    tmpAnagrams.push_back(strs[j]);
                    strs[j] = "$";
                }
            }
            _groupAnagrams.push_back(tmpAnagrams);
            }
        }

        sort(_groupAnagrams.begin(), _groupAnagrams.end());
        return _groupAnagrams;
    }
};
