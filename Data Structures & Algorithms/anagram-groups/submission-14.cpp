class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> mp;
        for(string str : strs){
            //generate key
            vector<int> freq(26, 0);
            for(char c : str){
                freq[c - 'a']++;
            }
            string key = "";
            for(int f : freq){
                key += to_string(f) + '#';
            }

            mp[key].push_back(str);
        }

        for(auto it : mp){
            anagrams.push_back(it.second);
        }
        return anagrams;
    }
};
