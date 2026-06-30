class Solution {
public:
    void backtrack(int start, int target, vector<int>& path, vector<vector<int>>&ans, 
    vector<int>& nums){
        //base case
        if(target < 0)return;
        if(target == 0){
            ans.push_back(path);
            return;
        }
            //1,2,2,4,5,6,9
            //Never start with the duplicate element
            //if dups comes in between, thats fine
            for(int i = start; i < nums.size(); i++){
                //start represent where the level started
                //i continues going further after backtracking
                //so i > start says, this is the level where u check duplicate
                if(i > start && nums[i] == nums[i - 1])continue;
                path.push_back(nums[i]);
                backtrack(i + 1, target - nums[i], path, ans, nums);
                //backtrack
                path.pop_back();
            }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort so duplicate combinations are generated in consistent order for proper deduplication in set
        sort(candidates.begin(), candidates.end());
        vector<int> path; 
        vector<vector<int>> ans;
        backtrack(0, target, path, ans, candidates);
        return ans;
    }
};