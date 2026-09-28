class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxSeq = 0;
        for(int i : s){
            //If its not valid start
            if(s.count(i - 1)){continue;}
            int curSeq = 1;
            int start = i;
            //Else its a valid start
            //now keep checking until the sequence exists
            while(s.count(start + 1)){
                curSeq++;
                //since abive count(start + 1) already verifies that start+1 exists
                //so ur new searchy keep becoming strat+1 as long as start+1 exists
                start = start + 1;
            }

            //update the max seq so far
            maxSeq = max(maxSeq, curSeq);
        }

        return maxSeq;

    }
};
