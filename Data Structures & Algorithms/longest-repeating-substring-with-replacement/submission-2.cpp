class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int longestSubstr = 0;
        for(int i = 0; i < s.size(); i++)
        {
            vector<int> freq(26, 0);
            int windowLen = 0, maxFreq = 0;
            for(int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'A']++;
                windowLen = j - i + 1; //representing substring
                //tracking max as you go
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                //the total unique elements you can replace to make whole substring same
                int needed = windowLen - maxFreq;
                //checking validity
                if(needed <= k)
                {
                    longestSubstr = max(longestSubstr, windowLen);
                }
                else{break;}
            }
        }
        return longestSubstr;
    }
};
