class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";
        unordered_map<char, int> mp;
        //preinsert t chars
        for(char c : t)
            mp[c]++;
        
        int minLen = INT_MAX, stInd = -1;
        int l = 0;
        int count = 0;
        for(int r = 0; r < s.size(); r++){
            
            //1. Check, if char is preinserted,it freq shld be > 0.
            //if so, increment count & decrease its freq;
            if(mp[s[r]] > 0){
                count++;
            }

            //2. Reduce frequency of current char
            mp[s[r]]--;

            //3. Check if count == t.size() => if we have used all chars
            //from t.If so,just shrink the window and keep storing min
            while(count == t.size()){
                if(r - l + 1 < minLen){
                    minLen = min(r - l + 1, minLen);
                    stInd = l;
                }
                //shrinking means, we're adding used chars back to original
                //freq
                mp[s[l]]++;
                if(mp[s[l]] > 0){// it means, we got preinserted char
                    count--;
                }
                l++;
            }
        }
        return stInd == -1 ? "" : s.substr(stInd, minLen);
    }
};
