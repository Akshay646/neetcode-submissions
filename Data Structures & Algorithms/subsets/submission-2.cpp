class Solution {
public:
    void backtrack(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(path);
            return;
        }
        //decision to include nums[i];
        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, res);

        //decision not to include nums[i]; 
        //executes after returning from include branch
        //backtrack by removing last element
        path.pop_back();
        backtrack(i + 1, nums, path, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> _subsets;
        vector<int> path;
        backtrack(0, nums, path, _subsets);
        return _subsets;
    }
};
