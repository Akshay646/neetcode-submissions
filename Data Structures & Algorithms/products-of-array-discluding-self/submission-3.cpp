class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int prefix = 1, suffix = 1;
        for(int i = 0; i < nums.size(); i++){
           //assign prefix at given i
           ans[i] *= prefix;
           prefix *= nums[i]; //=> this becomes prefix for next i
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] *= suffix;
            suffix *= nums[i]; //=> this become prefix for next i to be used
        }

        return ans;
    }
};
