class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> _set;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            int s = i + 1, e = n - 1;
            while(s < e)
            {
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0)
                {
                    _set.insert({nums[i], nums[s], nums[e]});
                }
                if(sum > 0)
                {
                    e -= 1;
                }
                else
                {
                    s += 1;
                }
            }
        }

        vector<vector<int>> ans(_set.begin(), _set.end());
        return ans;
    }
};
