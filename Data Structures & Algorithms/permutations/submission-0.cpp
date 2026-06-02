class Solution {
public:
    void permutation(vector<int>& path, vector<vector<int>>& ans, 
    vector<int>& nums, vector<bool>& used){
        //base case: when path size == nums size
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        //now generate permutations
        //If I start from some later index instead of 0, I may completely 
        //miss checking 2, which is the only unused element left. In permutations, 
        //any unused element can be picked next, so I must scan the entire array every time.
        for(int i = 0; i < nums.size(); i++){//level based recursion
            //we only add element if its not used
            if(!used[i]){
                path.push_back(nums[i]);
                used[i] = true;
                permutation(path, ans, nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path; vector<vector<int>> ans; 
    vector<bool> used(nums.size(), false);
    permutation(path, ans, nums, used);
    return ans;
    }
};
