class Solution {
public:
    int trap(vector<int>& height) {
        //brute force
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int l = 0, e = n - 1;
        int totalTrappedWater = 0;

        while(l < e)
        {
            //get the boubdaries
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[e]);

            //Now, as smaller wall/bar decides how much water current bar can hold
            //so if leftMax(max bar so far) is min, rightMax does not affect how much water
            //the current bar can hold
            //becuase for that bar, the min(L, R) will decides the water store for it(IMP)
            if(leftMax < rightMax)
            {
                totalTrappedWater += leftMax - height[l];
                l++;
            }
            else
            {
                totalTrappedWater += rightMax - height[e];
                e--;
            }
            
        }
        return totalTrappedWater;
    }
};
