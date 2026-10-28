class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> f(128, 0);
        int l = 0, r = 0;
        //prefil the t chars in freq
        for(char c : t){
            f[c]++;
        }
        int match = 0;
        int winStart = -1, winLen = INT_MAX;
        while(r < s.size()){
            
            //it means its preinserted
            if(f[s[r]] > 0){
                match++;
            }

            //expand the widnow as long as you're not filling
            //all t's chars
            f[s[r]]--;

            //shrinking when you have come across all t chars
            while(match == t.size()){
                //compute and keep stroing min len so far
                //we only store winStart when we find min len
                //than current window size
                if(r - l + 1 < winLen){
                    winLen = r - l + 1;
                    winStart = l;
                }

                //since you're shrinking, you need to put
                //back all chars which were used
                f[s[l]]++;

                //now if any char comes back to > 0, means
                //we have reach the point where our t starts
                if(f[s[l]] > 0){
                    //so decrement match since we restore
                    //one of chars of t
                    match--;
                }
                l++;
            }
            r++;
        }
        return winStart == -1 ? "" : s.substr(winStart, winLen);
    }
};
