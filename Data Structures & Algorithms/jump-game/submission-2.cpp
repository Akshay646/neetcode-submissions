class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int i = 0; i < nums.size(); i++){
            maxJump = max(maxJump, nums[i] + i);

            //if your maxJump can really reach the end itself, return true
            if(maxJump >= nums.size() - 1){
                return true;
            }

            //if by any chance if current pos(i) > maxJump, then its impossible to
            //move further, because none of the previously reachable positions could
            //jump far enough to reach pos in the first place → false.
            if(i >= maxJump){return false;}
        }

        return true;
    }
};
