class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& path, 
    vector<vector<int>>& res){
        //here path get filled first, the added to result
        //again after backtracking, it gets popped up with a few elements
        //and added other elements and again added in result and keeps going on
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
