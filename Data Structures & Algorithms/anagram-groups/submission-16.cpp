class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> grpAnagrams;
       vector<vector<string>> ans;

       for(string str : strs){
            vector<int> freq(26, 0);
            for(char c : str){
                freq[c - 'a']++;
            }
            //now generate a unique key for str
            string key = "";
            for(int i : freq){
                key += (char)i + '#';
            }
            grpAnagrams[key].push_back(str);
       }

       //now get all the grouped anagrams from map
       for(auto& a : grpAnagrams){
        ans.push_back(a.second);
       }
       return ans;
    }
};
