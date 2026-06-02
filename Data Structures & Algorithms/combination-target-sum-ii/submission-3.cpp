class Solution {
public:
    void backtrack(int start, int target, vector<int>& path, vector<vector<int>>&ans, vector<int>& nums){
            if(target == 0){
                ans.push_back(path);
                return;
            }

            for(int i = start; i < nums.size(); i++){
                if(nums[i] == nums[i - 1] && i != start){
                    continue;
                }
                if(nums[i] > target){break;}
                path.push_back(nums[i]);
                backtrack(i + 1, target - nums[i], path, ans, nums);
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