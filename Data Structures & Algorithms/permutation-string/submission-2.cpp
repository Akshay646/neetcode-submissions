class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        //Generate Frequency array for s1
        for(char c : s1)
        {
            f1[c - 'a']++;
        }
        //generate frequency array for a substring len(s1) in s2 for initial check
        for(int i = 0; i < s1.size(); i++)
        {
            f2[s2[i] - 'a']++;
        }
        //check if they match(pruning)
        if(f1 == f2){return true;}

        int left = 0;
        //now start matching s1 in s2 for further match
        for(int right = s1.size(); right < s2.size(); right++)
        {
            f2[s2[left] - 'a']--;//shrink window from left
            f2[s2[right] - 'a']++; //expand window to right by 1

            //check now if the current windows matches with s1
            if(f1 == f2){return true;}

            left++;
        }

        return false;
    }
};
