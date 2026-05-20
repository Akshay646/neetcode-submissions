class Solution {
public:
    bool isValidSubstring(string s, vector<int> freq, int k)
    {
        //Get no. of unique elements
        int noOfUniques = s.size() - *max_element(freq.begin(), freq.end());

        return noOfUniques <= k;
    }
    int characterReplacement(string s, int k) {
        
        int longestSubstr = 0;
        for(int i = 0; i < s.size(); i++)
        {
            string tmp = "";
            vector<int> freq(26, 0);
            for(int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'A']++;
                tmp += s[j];
                if(isValidSubstring(tmp, freq, k))
                {
                    longestSubstr = max(longestSubstr, (int)tmp.size());
                }
                else{break;}
            }
        }
        return longestSubstr;
    }
};
