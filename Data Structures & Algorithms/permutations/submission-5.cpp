class Solution {
public:
    void dfs(vector<int>& path, unordered_map<int, bool>& seen,
    vector<vector<int>>& ans, vector<int>& nums){

        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!seen[nums[i]]){
                path.push_back(nums[i]);
                seen[nums[i]] = true;

                dfs(path, seen, ans, nums);
                //backtrack
                path.pop_back();
                seen[nums[i]] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path; unordered_map<int, bool> seen;
    vector<vector<int>> ans;
    dfs(path, seen, ans, nums);
    return ans;
    }
};
