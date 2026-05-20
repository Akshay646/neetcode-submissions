class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int n = heights.size();
        for(int i = 0; i < n; i++)
        {
            int minBarSoFar = INT_MAX;//acts as height/lenght
            for(int j = i; j < n; j++)
            {
                minBarSoFar = min(minBarSoFar, heights[j]);
                //Area formula; i.e. length(minBarSoFar) * width((j - i + 1))
                maxArea = max(maxArea, minBarSoFar * (j - i + 1));
            }
        }

        return maxArea;
    }
};