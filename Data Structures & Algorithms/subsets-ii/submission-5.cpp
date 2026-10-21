class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(path);
            return;
        }

        //take current element
        path.push_back(nums[i]);
        dfs(i + 1, nums, path, ans);

        //now exclude elements until those are equal
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        path.pop_back();
        dfs(i + 1, nums, path, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(0, nums, path, ans);
        return ans;
    }
};
