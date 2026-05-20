class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int right = 0;
        vector<int> ans;
        while(right <= nums.size() - k)
        {
            int limit = right + k;
            int maxEl = *max_element(nums.begin() + right, nums.begin() + limit);
            ans.push_back(maxEl);
            right++;
        }
        return ans;
    }
};
