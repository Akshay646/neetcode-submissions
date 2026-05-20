class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int n = nums.size() - 1;
        int minELe = INT_MAX;
        //4,5,6,1,2 3
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[l]){//left hald is sorted
                minELe = min(minELe, nums[l]);
                l = mid + 1;
            }
            else{
                minELe = min(minELe, nums[mid]);
                r = mid - 1;
            }
        }

        return minELe;
    }
};
