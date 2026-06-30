class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& path, 
    vector<vector<int>>& res){
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, res);

        path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> _subsets;
        vector<int> path;
        backtrack(0, nums, path, _subsets);
        return _subsets;
    }
};
