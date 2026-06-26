class Solution {
public:
    void permutation(int ind, vector<vector<int>>& ans, 
    vector<int>& nums){
      if(ind == nums.size()){
        ans.push_back(nums);
        return;
      }

      //try placing element at ind, by swapping (nums[ind], nums[i])
      //where i goes from idx to n
      for(int i = ind; i < nums.size(); i++){
        swap(nums[ind], nums[i]);
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
