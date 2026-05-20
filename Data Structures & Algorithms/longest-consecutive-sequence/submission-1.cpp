class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //2,3,4,5,10,20
        int longestSeq = 0, longestSeqSoFar = 1;
        if(nums.size() <= 0){return 0;}
        sort(nums.begin(), nums.end());

        for(int i = 1; i <= nums.size() - 1; i++)
        {
            if(nums[i] == nums[i - 1]){continue;}
            if(nums[i] - nums[i - 1] == 1)
            {
                longestSeqSoFar++;
            }
            else
            {
                longestSeq = max(longestSeq, longestSeqSoFar);
                longestSeqSoFar = 1;
            }
        }

        //Why we update here, because if last element is also consecutive,
        //i.e we ended up getting sequence until last
        //the control will never reach else statement to update the 
        //longestSeqSoFar

        longestSeq = max(longestSeq, longestSeqSoFar);

        return longestSeq;
    }
};
