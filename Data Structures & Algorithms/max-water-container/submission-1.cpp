class Solution {
public:
    int maxArea(vector<int>& heights) {
       int l = 0, r = heights.size() - 1;

       int _maxArea = 0;
       while(l < r){
        //calculate the area;
        int cArea = min(heights[l], heights[r]) * (r - l);
        _maxArea = max(cArea, _maxArea);

        if(heights[l] < heights[r]){
            //water is already determined by lower bar(l), which will
            //never cap water in future
            l++;
        }
        else{
            r--;
        }
       }
       return _maxArea;
    }
};
