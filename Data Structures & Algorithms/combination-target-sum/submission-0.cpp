class Solution {
public:
    void backtrack(int ind, int target, vector<int>& path, vector<vector<int>>& ans,
    vector<int>& nums){
       
       //if target becomes < 0 even before you reach an end of array, just return;
       if(target < 0){
        return;
       }
        //when u reach the end, you always have possible valid subsequence
        if(ind == nums.size()){
            // you path contains subsequence with sum = target
            if(target == 0){
            ans.push_back(path);
            }
            return;   
        }

        //pick an index multiple times. i.e ind does not move ind + 1 on call
        path.push_back(nums[ind]);
        backtrack(ind, target - nums[ind], path, ans, nums);

        //not pick and move to next index
        path.pop_back(); //as nums[i] was already added in pick call, so remove it
        backtrack(ind + 1, target, path, ans, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path; vector<vector<int>> ans;
        backtrack(0, target, path, ans, nums);
        return ans;
    }
};
