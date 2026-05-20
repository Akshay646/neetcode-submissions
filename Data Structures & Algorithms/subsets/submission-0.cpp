class Solution {
public:
    void backtrack(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(path);
            return;
        }
        //take current element
        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, res);

        //not take current element, this'll only execute after complete recurion path
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
