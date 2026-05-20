class Solution {
public:
    int search(vector<int>& nums, int target) {
        //5 6 7 8 1 2 3
        //in rotated sorted array, always  take advantage of sorted property
        //1. l and h pointers moved only with respect to ar[l], ar[h] & target
        //unlike tradition BS on whole sorted array
        int l = 0, r = nums.size() - 1;
        int n = nums.size() - 1;

        while(l <= r){ // <= as what if an array has only a element
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            //if left half is sorted
            else if(nums[mid] >= nums[l]){
                //if target belongs in [L..M]
                if(target >= nums[l] && target <= nums[mid]){
                    r = mid - 1; //new search space
                }else{
                    l = mid + 1;
                }
            }
            else{//right half is sorted
                 //if target belongs in [M..R]
                if(target >= nums[mid] && target <= nums[r]){
                    l = mid + 1; //new search space
                }else{
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
