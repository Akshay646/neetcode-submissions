class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = 0, rMax = 0;
        int trappedWater = 0;

        //start from both ends
        while(l < r){
            //keep updating max from both sides
            //lMax = max height seen so far from left
            //rMax = max height seen so far from right
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            //whichever max is smaller, that side is the limiting boundary
            //so we can calculate water for that bar and move that pointer
            if(lMax < rMax){
                //since lMax < rMax, we already have a right boundary
                //bigger than lMax, so water at l is decided by lMax
                trappedWater += lMax - height[l];
                l++;
            }
            else{
                //since rMax <= lMax, we already have a left boundary
                //bigger than or equal to rMax, so water at r is decided by rMax
                trappedWater += rMax - height[r];
                r--;
            }
        }

        return trappedWater;
    }
};