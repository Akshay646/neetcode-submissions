    class Solution {
    public:
        string getFrequencyString(string str){
            int arr[26] = {0};
            string key;
            for(char c : str){
                arr[c - 'a']++;
            }
            for (int cnt : arr) {
                key += '#';
                key += to_string(cnt);
            }
            return key;
        }
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            vector<vector<string>> ans;
            
            for(string str : strs){
                mp[getFrequencyString(str)].push_back(str);
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
