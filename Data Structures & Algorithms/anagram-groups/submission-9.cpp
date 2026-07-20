class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string str : strs){
            string tmp = str;
            sort(str.begin(), str.end());
            mp[str].push_back(tmp);
        }
        for(const auto& [_, val] : mp){
            vector<string> tm;
            for(string s : val){
                tm.push_back(s);
            }
            ans.push_back(tm);
        }
        return ans;
    }
};
