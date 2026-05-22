class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = -1, rightMax = -1;
        int totalWater = 0;
        while(left < right){
            //store leftMax and rightMax
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            //A. Remember, we only need the minimum bar among leftMax and rightMax
            //to calculate the  water at ith bar
            //B. Whichever side is min among left or right pointer, we shift those
            if(leftMax < rightMax){ //leftMax is minimum
                totalWater += leftMax - height[left];
                left++;
            }
            else{//rightMax is minimum
                totalWater += rightMax - height[right];
                right--;
            }
        }
        return totalWater;
    }
};
