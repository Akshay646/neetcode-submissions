class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> S1(26, 0), S2(26, 0);
        if(s1.size() > s2.size())return false;
        //First check in s2(0 ... s1.size())
        for(char c : s1){
            S1[c - 'a']++;
        }
        for(int i = 0; i < s1.size(); i++){
            S2[s2[i] - 'a']++;
        }
        if(S1 == S2)return true;

        //Second check of s1 as window in s2 from (1 to s2.size())
        int l = 0, r = s1.size();
        while(r < s2.size()){
            S2[s2[l] - 'a']--;
            S2[s2[r] - 'a']++;
            if(S1 == S2){return true;}
            r++;
            l++;
        }
        return false;
    }
};
