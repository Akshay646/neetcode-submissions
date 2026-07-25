class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0,r = nums.size() - 1;
        int minAns = INT_MAX;
        while(l <= r){
            int m = l + (r - l) / 2;
            //check if left part is sorted
            //why >= and not just > becuase lets say an input array
            //[2,1], l = 0, m is also equals to 0, thats why
            //you always check >=
            if(nums[m] >= nums[l]){
                //store the min and discard the sorted part
                //sice left part is sorted
                //store only if minAns is < than current min
                if(nums[l] < minAns)
                    minAns = nums[l];
                l = m + 1;
            }
            //Right part is sorted
            else{
                //store the min
                //since right part is sorted
                //store only if minAns is < than current min
                if(nums[m] < minAns)
                    minAns = nums[m];
                r = m - 1;
            }
        }
        return minAns;
    }
};
