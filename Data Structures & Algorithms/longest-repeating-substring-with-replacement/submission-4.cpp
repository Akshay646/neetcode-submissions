class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int longestSubstr = 0;
        int left = 0, windowLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        for(int right = 0; right < s.size(); right++)
        {
            //Add frequencies
            freq[s[right] - 'A'] ++;
            //keep stroing maxFreq element
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            //getting current substring/window lenght
            windowLen = right - left + 1;
            //check if substring is valid(needed <= k)
            int needed = windowLen - maxFreq; //unique elements
            if(needed > k)//invalid->shrink window(left++)->remove from map
            {
                freq[s[left] - 'A']--;
                left++;
            }

            //If it comes here, its valid. Just store the max lenght everytime

             longestSubstr = max(longestSubstr, right - left + 1);
        }
        return longestSubstr;
    }
};
