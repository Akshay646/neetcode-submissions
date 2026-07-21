class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<int> hash;
        int ans = 0;
        for(int r = 0; r < s.size(); r++){
            //remove elements until duplicate found
            while(hash.count(s[r])){
                hash.erase(s[l]);
                l++;
            }
            hash.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
