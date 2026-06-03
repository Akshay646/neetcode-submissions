class Solution {
public:
    void permutation(int ind, vector<vector<int>>& ans, 
    vector<int>& nums){
       //base case when our ind reaches end means one of the path done swapping
       if(ind == nums.size()){
        //as elements in nums itself are swapped
        ans.push_back(nums);
        return;
       }

       //now Try every element on every level and go deep one by one,
       //while coming  back, store result, undo choice, keep swapping
       for(int i = ind; i < nums.size(); i++){
        //IMPORTANT: Ind stays the same hence you keeo swapping ind with increamenting i
        swap(nums[ind], nums[i]);
        //now u r setting new position with which incrementing i(nums[i]) will be swapped
        permutation(ind + 1, ans, nums);
        //undo the choice
        swap(nums[ind], nums[i]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans; 
    permutation(0, ans, nums);
    return ans;
    }
};
