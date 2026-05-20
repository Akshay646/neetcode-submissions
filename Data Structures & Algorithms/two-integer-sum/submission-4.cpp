class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            vp.push_back({nums[i], i});
        }
        sort(vp.begin(), vp.end());
        int start = 0, end = vp.size() - 1;
        while(start < end)
        {
            int currentSum = vp[start].first + vp[end].first;
            if(currentSum == target)
            {
                return {min(vp[start].second, vp[end].second),
                        max(vp[start].second, vp[end].second)};
            }
            else if(currentSum > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return {};
    }
};
