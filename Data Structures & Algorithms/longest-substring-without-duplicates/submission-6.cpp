class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longStr = 0;
        int left= 0, right = 0;
        unordered_set<char> hash;
        for(right = 0; right < s.size(); right++)
        {
            while(hash.count(s[right]))
            {
                //We erase elements from sets until the duplicate is removed
                //Note that, until this, the right is still not yet added
                hash.erase(s[left]);
                left++;//shrinking the window from left until duplicate removed
            }
            hash.insert(s[right]);
            longStr = max(longStr, right - left + 1);
        }
        return longStr;
    }
};
