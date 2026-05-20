class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //brute force with O(n^2) space and time
        int longStr = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int tmpLen = 0;
            unordered_set<char> hash;
            for(int j = i; j < s.size(); j++)
            {
                if(!hash.count(s[j]))
                {
                    tmpLen++;
                    longStr = max(longStr, tmpLen);
                    hash.insert(s[j]);
                }
                else{break;}
            }
        }
        return longStr;
    }
};
