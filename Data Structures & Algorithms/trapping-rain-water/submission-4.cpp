class Solution {
public:
    int trap(vector<int>& height) {
        //brute force
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        // Fix initialization
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        int tmpMax1 = height[0], tmpMax2 = height[n - 1];
        int totalTrappedWater = 0;

        //storing left and right maxes for each i
        for(int i = 1; i < n; i++)
        {
            tmpMax1 = max(tmpMax1, height[i]);
            tmpMax2 = max(tmpMax2, height[n - i - 1]);
            leftMax[i] = tmpMax1;
            rightMax[n - i - 1] = tmpMax2;
        }

        //calculating area which can be store at height i
        for(int i = 0; i < n; i++)
        {
            totalTrappedWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalTrappedWater;
    }
};
