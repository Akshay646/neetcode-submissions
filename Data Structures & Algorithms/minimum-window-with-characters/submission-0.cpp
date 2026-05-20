class Solution {
public:
    string minWindow(string s, string t) {

        // hash will store frequency of required chars from t
        // we take size 256 because s/t can contain uppercase, lowercase, symbols etc
        vector<int> hash(256, 0);

        int right = 0, left = 0;
        int startingInd = -1;        // answer window start
        int count = 0;               // how many chars of t we have matched so far (including duplicates)
        int minWinSize = INT_MAX;

        // fill need map for t
        for(char c : t) {
            hash[c]++;   // IMPORTANT: use direct char indexing, no '-a'
        }

        // expand window using right
        while(right < (int)s.size()) {

            // if this char is still needed (>0), then it contributes to matching
            // we know that, we have got one required chat among the t
            if(hash[s[right]] > 0) {
                count++;
            }

            // consume it from hash (even if extra, it will go negative)
            hash[s[right]]--;

            // when count == t.size() means we got all required chars (valid window)
            while(count == (int)t.size()) {

                // update answer if this window is smaller
                if(right - left + 1 < minWinSize) {
                    minWinSize = right - left + 1;
                    startingInd = left;
                }

                // now we want to shrink from left side
                // so first "remove" s[left] from window (undo consumption)
                hash[s[left]]++;

                // if after putting back, hash becomes > 0, that means:
                // we removed a required char and now window is no longer valid
                if(hash[s[left]] > 0) {
                    count--;
                }

                left++; // now shrink window
            }

            right++; // move right forward
        }

        // if never found any valid window
        return startingInd == -1 ? "" : s.substr(startingInd, minWinSize);
    }
};
