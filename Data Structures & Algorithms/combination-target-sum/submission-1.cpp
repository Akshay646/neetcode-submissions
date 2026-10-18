class Solution {
public:
    void dfs(int start, vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int target){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            if(target < 0){return;}
            //take current element
            path.push_back(nums[i]);
            dfs(i, nums, ans, path, target - nums[i]);

            //backtrack after you complete eacg recursion depth
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, nums, ans, path, target);
        return ans;
    }
};
