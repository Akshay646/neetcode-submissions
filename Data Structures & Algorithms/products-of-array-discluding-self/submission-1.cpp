class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //1,2,8,48
        //48,48,24,6
        int n = nums.size();
        vector<int>result(n, 1);
        int prefix = 1, suffix = 1;
        for(int i = 0; i < n; i++)
        {
            result[i] *= prefix;
            prefix *= nums[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            result[n - i - 1] *= suffix;
            suffix *= nums[n - i - 1];
        }
        return result;
    }
};
