class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = 0, rMax = 0;
        int trappedWater = 0;

        //start from both the ends
        while(l < r){
            //store max from both the ends
            //these only updates when they get max value than themselves
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            //now decide which bar is minimum
            if(lMax < rMax){//left bar is minimum
                trappedWater += lMax - height[l];
                l++; //discraded/shifted l since lMax is min
            }
            else{//right bar is minimum
                trappedWater += rMax - height[r];
                r--; //discraded/shifted r since rMax is min
            }
        }

        return trappedWater;
    }
};
