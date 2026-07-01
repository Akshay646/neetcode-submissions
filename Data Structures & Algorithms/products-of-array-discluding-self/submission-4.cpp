class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 1,2,4,6
        // 48,24,12,8

        vector<int> ans(nums.size());
        int prod = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            ans[i] = prod; 
            prod *= nums[i];
        }
        prod = 1;
        for(int i = n - 1; i >= 0; i--){
            //as in two pref and suff array, when we make one result array
            //we generally multiply both suff[i] * preff[i] to get ans[i]
            ans[i] *= prod;
            prod *= nums[i];
        }

        return ans;
    }
};
