class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> f(128, 0);
        int l = 0;
        int startInd = -1, minLen = INT_MAX;

        //preinsert t chars in freq, so when we encounter +ve
        //char,it means its one of the chars from t, so increment
        //count,once count == t.size(), we know we have found
        //t in the given range[l..r]
        int count = 0;
        for(char c : t){
            f[c]++;
        }
        for(int r = 0; r < s.size(); r++){
            //check if its preinserted,means f > 1
            //whenever its > 0, we encounter one of the t's char
            if(f[s[r]] > 0){
                count++;
            }
            //expand the window
            //we decrement as we expand, which lets us keep track
            //of t's chars properly
            f[s[r]]--;

            //now as long as t.size() == count, shrink window
            //where we increment the f[s[l]]++ which again let us
            //keep track when we reach one of the t's char
            while(count == t.size()){
                //store the max so far
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startInd = l;
                }
                //shrink window
                f[s[l]]++;
                //now if you encounter t's char i.e. f[s[l]]
                //become > 0 means as same as preinserted, we
                //reduce count as per rule we decided
                if(f[s[l]] > 0){
                    count--;
                }
                l++;
            }
        }

        return startInd == -1 ? "" : s.substr(startInd, minLen);
    }
};
