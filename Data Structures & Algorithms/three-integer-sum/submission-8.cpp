class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)//i will be an anchor
        {
            //Skipping duplicate anchors as reusing same anchor will definitly cause duplicates
            if(i > 0 && nums[i] == nums[i - 1]){continue;}

            //Solving two sum here
            int s = i + 1, e = n - 1;
            while(s < e)
            {
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    //move both pointers
                    s++; e--;
                    //Skipping both pointer
                    //skip s if its as same as s - 1 as it will cause duplicates
                    while(s < e && nums[s] == nums[s - 1]){s++;}
                    //skip e if its as same as e + 1 until the current e is not as same as
                    // old e as it will cause duplicates
                    while(s < e && nums[e] == nums[e + 1]){e--;}
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
