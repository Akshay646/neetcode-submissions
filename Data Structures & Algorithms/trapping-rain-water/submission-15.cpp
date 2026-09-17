class Solution {
public:
    int trap(vector<int>& height) {
        int lMax = 0, rMax = 0;
        int l = 0, r = height.size() - 1;
        int trappedWater = 0;
        while(l < r){
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            if(lMax < rMax){
                trappedWater += min(lMax, rMax) - height[l];
                l++;
            }
            else{
                trappedWater += min(lMax, rMax) - height[r];
                r--;
            }
        }
        return trappedWater;
    }
};
