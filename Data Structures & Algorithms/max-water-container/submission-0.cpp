class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0, end = heights.size() - 1;
        int maxArea = 0;
        while(start < end)
        {
            int currentArea = min(heights[start], heights[end]) * (end - start);
            maxArea = max(maxArea, currentArea);
            
            //Now, shift pointers based on min height
            if(heights[start] < heights[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return maxArea;
    }
};
