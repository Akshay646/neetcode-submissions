class Solution {
public:
    bool recur(int pos, vector<int>& nums, vector<int>& dp){
        //when you reach the end
        if(pos >= nums.size() - 1){return true;}
        //check if cache is available in dp
        if(dp[pos] != -1){return dp[pos];}
        //if you're are at 0 by any chance in anywhere in branch
        if(nums[pos] == 0){return false;}

        //Now, from given position(pos), you have nums[i] jumps option
        for(int i = 1; i <= nums[pos]; i++){
        //now by any chance, if you jump to 0, return false as that's invalid pos
            if(recur(i + pos, nums, dp)){
                return dp[i + pos] = true;
            }
        }

        //Default, it may or may not execute, but you never reached an end
        return dp[pos] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recur(0, nums, dp);
    }
};
