class Solution {
public:
    void permutation(int ind, vector<vector<int>>& ans, 
    vector<int>& nums){
        //base case: when your idx reaches end and u done swapping, u get valid
        //permutation
        if(ind == nums.size()){
           //since we have swapped the array, copy it as is in ans
           ans.push_back(nums);
           return;
        }

        for(int i = ind; i < nums.size(); i++){//level based recursion
           swap(nums[ind], nums[i]);
           //here we do not pass i + 1, because here we are not moving to next index,
           //but we are deciding the next position we will fix to swap elements 
           //from that ind to n - 1
           permutation(ind + 1, ans, nums);
           swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans; 
    permutation(0, ans, nums);
    return ans;
    }
};
