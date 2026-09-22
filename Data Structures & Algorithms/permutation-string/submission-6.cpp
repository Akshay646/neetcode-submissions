class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        if(s1.size() > s2.size()){return false;}

        //calculate first window for s1 and s2 both initially
        //since s1 size limits the window
        for(int i = 0; i < s1.size(); i++){
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }

        //check at this point if they are actually equal
        if(f1 == f2){return true;}

        //now on s2, keep adding new char and removing old one, maintain size of s1
        //and keep chekcing if they become equal by any chance
        int l = 0;
        int r = s1.size();
        while(r < s2.size()){
            f2[s2[l] - 'a']--;
            f2[s2[r] - 'a']++;

            if(f1 == f2){
                return true;
            }
            l++;
            r++;
        }
        return false;
    }
};
