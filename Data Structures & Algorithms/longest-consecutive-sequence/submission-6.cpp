class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //0,1,1,2
        //edge case to cover wrong return of lConsec
        if(nums.size() == 0){return 0;}
        sort(nums.begin(), nums.end());
        int lConsec = 1;
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){//skip dupes
                continue;
            }
            else if(nums[i] - nums[i - 1] == 1){//gets consecutive, so count++
                count++;
            }
            else{//consecutiveness breaks here, so update ans & resent count
                lConsec = max(lConsec, count);
                count = 1;
            }
        }

        //also we make sure if at the end if it does not goes in else we still
        //may have max  count in count
        return max(lConsec, count);
    }
};