class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, j = 0, k = 0;
        //sort is important for two pointers and avoid duplicates
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            //skip duplicates, as same nums[i] in future will cause duplicates
            if(i > 0 && nums[i] == nums[i - 1])continue;
            //two pointers, variation of BS
            int j = i + 1, k = n - 1;
            while(j < k){//valid traversal condition

                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;  k--;
                     //as we may have got sum above, now skip the duplicates if any
                while(j < k && nums[j] == nums[j - 1])j++;
                while(j < k && nums[k] == nums[k + 1])k--;
                }
                else if(sum < 0){
                    j++;//to increase the sum
                }
                else{
                    k--; //sum > 0 so decrease the sum
                }
            }
        }
        return ans;
    }
};