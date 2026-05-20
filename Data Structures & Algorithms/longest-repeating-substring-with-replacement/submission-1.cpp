class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int longestSubstr = 0;
        for(int i = 0; i < s.size(); i++)
        {
            vector<int> freq(26, 0);
            int windowLen = 0;
            for(int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'A']++;
                windowLen = j - i + 1; //representing substring
                int uniques = windowLen - *max_element(freq.begin(), freq.end());
                //checking validity
                if(uniques <= k)
                {
                    longestSubstr = max(longestSubstr, windowLen);
                }
                else{break;}
            }
        }
        return longestSubstr;
    }
};
