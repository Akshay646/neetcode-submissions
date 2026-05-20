class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //1,2,8,48
        //48,48,24,6
        int p1 = 1, p2 = 1, n = nums.size();
        vector<int>prod1(n), prod2(n), result(n);
        for(int i = 0; i < n; i++)
        {
            p1 *= nums[i];
            p2 *= nums[n - i - 1];
            prod1[i] = p1;
            prod2[n - i - 1] = p2;
        }
        
        result[0] = prod2[1];
        result[n - 1] = prod1[n - 2];
        for(int i = 1; i < n - 1; i++)
        {
            int prod = prod1[i -1] * prod2[i + 1];
            result[i] = prod;
        }
        return result;
    }
};
