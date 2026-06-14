class Solution {
public:
    string minWindow(string s, string t) {
       int stInd = -1, minLen = INT_MAX;
       vector<int> freq(256, 0);
       int count = 0, m = s.size(), n = t.size();

       //Two pointers, L - Shrinks, R - Expand
       int l = 0, r = 0;

       //Preinsert chars if t which will help manage count of used/unused from t
       for(char c : t){freq[c]++;}
       while(r < m){
        //Check if char is used from t : freq[s[r]] will be > 0 as its preinserted
        if(freq[s[r]] > 0){count += 1;}

        //mark frequency of current element as used in freq map
        freq[s[r]]--;

        //Now, if count == t.size(), means we have used all the chars from t, start
        //shrinking window to find minLen by also verifying we still have valid window
        while(count == n){
            //First store minimum lenght
            if(r - l + 1 < minLen){
                minLen = r - l + 1;
                stInd = l;
            }
            //Also undo frequency (add it again into freq map)
            freq[s[l]]++;
            //Now after by any chnace, freq[s[l]] > 0, it means u have put that char back at t
            //IMP: freq[s[l/r]] will only go beyond 0 when it is one of that chars from t
            if(freq[s[l]] > 0){
                count = count - 1;
            }

            //shrink window
            l++;
        }
        
        //expand window
        r += 1;
       }

       return stInd == -1 ? "" : s.substr(stInd, minLen);
    }
};
