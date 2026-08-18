class Solution {
public:
    //best appraoch with O(n) space and time
    int trap(vector<int>& height) {
        //1. To find the water at given bar, we need a few important
        //entities to be known
        //a. leftMax, rightMax. smaller between these two bars
        //caps the water as water overflows on top of it.
        //2. Usually we maintain two arrays, leftMax rightMax, so
        //for i in heights[i], leftMax[i] & rightMax[i] gives you
        //left max and right max for given ith height
        //but you can maintain a single array called cappedBars, 
        //in 1st pass, store max from left at each bar, and do
        //second pass and since you know left max for given i, you
        //can simply store min(cappedBars[i], heights[i])
        //3. Then calcuate water trapped by each bar as
        //height[i] - cappedBars[i]
        int n = height.size();
        vector<int> cappedBars(n);
        int leftMax = height[0];
        //first pass : calcuate left max
        for(int i = 0; i < n; i++){
            leftMax = max(leftMax, height[i]);
            cappedBars[i] = leftMax;
        }
        //second pass : calcuate right max and then store minimum
        //between them
        int rightMax = height[n - 1];
        for(int i = n - 1; i >= 0; i--){
            rightMax = max(rightMax, height[i]);
            //store minimum between them
            cappedBars[i] = min(cappedBars[i], rightMax);
        }

        //calculate total water trapped per bar
        int totalTrappedWater = 0;
        for(int i = 0; i < n; i++){
            totalTrappedWater += cappedBars[i] - height[i];
        }
        return totalTrappedWater;
    }
};