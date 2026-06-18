class Solution {
public:
    void dfs(int idx, vector<vector<int>>& ans, vector<int>& nums){
       if(idx == nums.size()){
        ans.push_back(nums);
        return;
       }
       for(int i = idx; i < nums.size(); i++){
        //idx  stays same, loop runs from i = idx to nums.size()
        swap(nums[idx], nums[i]);
        dfs(idx + 1, ans, nums);
        //backtrack to retain previous step
        swap(nums[idx], nums[i]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    dfs(0, ans, nums);
    return ans;
    }
};
