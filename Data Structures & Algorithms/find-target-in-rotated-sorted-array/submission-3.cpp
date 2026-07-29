class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ind = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            //checks if left half is sorted
            else if(nums[l] <= nums[mid]){
                //now check if target lies in the left part
                if(target >= nums[l] && target <= nums[mid]){
                    r = mid - 1;
                }
                //becuase the left part is sorted but target does not lie in there
                //so, we need to update the search space to right
                else{
                    l = mid + 1;
                }
            }
            //if not left, right part is sorted
            else{
                //now check if target lies in here
                if(target >= nums[mid] && target <= nums[r]){
                    l = mid + 1;//your search space becomes right
                }
                else{
                    //right is sorted, but target does not lie in this part
                    //you update search space to left
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
