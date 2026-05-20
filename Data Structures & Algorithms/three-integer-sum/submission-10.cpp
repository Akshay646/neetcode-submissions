class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // /[-1,0,1,2,-1,-4]
        // [-4,-1,0,1,1,2]
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n =  nums.size();
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int l = i + 1, r = n - 1;
            //two pointers
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--; //shoft both

                //now after sum == 0, you can not use same l or r as previous l and r
                //i.e l-1 and r+1(alread used) will produce the duplicate triplate

                //skip duplicates form left to right
                //how sure of comparing with nums[l - 1]?
                //l's increated after sum became 0
                while(l < r && nums[l] == nums[l - 1]){
                    l++;
                }

                //skip duplicates form left to right
                //why sure of r + 1, ag this point r is already decremented after sum become 0
                while(l < r && nums[r] == nums[r + 1]){
                    r--;
                }
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};
