class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>& path, set<vector<int>>& subsets){
        if(i == nums.size()){
            subsets.insert(path);
            return;
        }

        //take the current element
        path.push_back(nums[i]);
        //go to next index:
        dfs(i + 1, nums, path, subsets);

        //now this will execute after current recursion stack when
        //returns, so undo choices, and explore other indices
        path.pop_back();
        dfs(i + 1, nums, path, subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> path;

        dfs(0, nums, path, res);
        vector<vector<int>> ans(res.begin(), res.end());

        return ans;
    }
};
