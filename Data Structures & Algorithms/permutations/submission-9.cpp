class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, unordered_map<int, bool>& hash, vector<vector<int>>& ans){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        //For loop helps traverse recursion level by level
        //So before recursion call(dfs), whatever you do is in the
        //level but in the same depth
        //after backtrack, the next level starts
        for(int i = 0; i < nums.size(); i++){
            if(!hash[nums[i]]){
                path.push_back(nums[i]);
                hash[nums[i]] = true;
                dfs(nums, path, hash, ans);

                //backtrack becuase you're returning from recursion
                //above, so undo choices and come to previous state
                //to explore new permutations
                path.pop_back();
                hash[nums[i]] = false;
                //no need to separatly call dfs(i+1, ..) again,
                //since for loop handles it
            }
        }
    }   
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        unordered_map<int, bool> hash;
        vector<vector<int>> ans;

        dfs(nums, path, hash, ans);
        return ans;
    }
};
