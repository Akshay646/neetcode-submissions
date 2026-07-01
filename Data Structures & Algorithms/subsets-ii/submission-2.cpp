class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& path, 
    set<vector<int>>& s){
        s.insert(path);

        //now generate all possible subsets without dups
        //for loop make sure you do not go out of bound
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, s);
            path.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> path; set<vector<int>> s;
        backtrack(0, nums, path, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
