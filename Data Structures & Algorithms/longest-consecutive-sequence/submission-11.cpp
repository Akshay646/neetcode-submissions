class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxSeq = 0;
        for(int i = 0; i < nums.size(); i++){
            //If its not valid start
            if(s.count(nums[i] - 1)){continue;}
            int curSeq = 1;
            int start = nums[i];
            //Else its a valid start
            //now keep checking until the sequence exists
            while(s.count(start + 1)){
                curSeq++;
                start = *s.find(start + 1);
            }

            //update the max seq so far
            maxSeq = max(maxSeq, curSeq);
        }

        return maxSeq;

    }
};
