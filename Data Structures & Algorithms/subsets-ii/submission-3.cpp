class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& path, 
    vector<vector<int>>& ans){
        ans.push_back(path);

        //now generate all possible subsets without dups
        //for loop make sure you do not go out of bound
        for(int i = start; i < nums.size(); i++){
            //now check if you are on the same level( i > start) and
            //if current element was not ever a starting point for any subsequence
            //previously
            if(i > start && nums[i] == nums[i - 1])continue;
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, ans);
            path.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path; set<vector<int>> s;
        backtrack(0, nums, path, ans);
        return ans;
    }
};
