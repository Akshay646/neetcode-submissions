class Solution {
public:
    void backtrack(int start, int target, vector<int>& path, vector<vector<int>>&ans, vector<int>& nums){
        //base cases
        
            //check of we have got valid subsequence
            if(target == 0){
                ans.push_back(path);
                return;
            }
        

        //try all elements as starting points
        for(int i = start; i < nums.size(); i++){//LEVEL
            // Skip duplicate branches on the same recursion level.
            // Do not skip when i == start because this is the first candidate
            // of the current recursion level and may lead to valid combinations.
            if(i != start && nums[i] == nums[i - 1])continue;
            //if nums[i] > target, it will go -ve and we never reach the target
            if(nums[i] > target)return;
            //add element in path
            path.push_back(nums[i]);
            backtrack(i + 1, target - nums[i], path, ans, nums);
            //after u come from recursion, remove the last choice
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