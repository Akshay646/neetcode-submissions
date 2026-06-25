class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int lConsec = 0;
        for(int i : s){
            //Its predecessor exists in the set already
            int count = 1;
            if(s.count(i - 1)){
               continue;
            }
            
            //when its the start
            while(s.count(i + 1)){
                count++;
                i++;
            }
            lConsec = max(lConsec, count);
        }
        return lConsec;
    }
};