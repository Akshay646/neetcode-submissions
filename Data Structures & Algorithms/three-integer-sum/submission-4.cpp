class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]){continue;}
            int s = i + 1, e = n - 1;
            while(s < e)
            {
                if(nums[s] == nums[s + 1]){s++;}
                if(nums[e] == nums[e - 1]){e--;}
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++; e--;
                }
                else if(sum > 0)
                {
                    e -= 1;
                }
                else
                {
                    s += 1;
                }
            }
        }

        return ans;
    }
};
