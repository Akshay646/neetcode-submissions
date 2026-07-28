class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //use max heap to maintain max at top
        deque<int> dq;
        vector<int> ans;
        int i = 0;
        while(i < nums.size()){
            //1. If deque contains out of bound element,remove it
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            //2. Remove all elements from back which are lesser 
            //than curent max at front as those will never become max any later
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            //3. You have got the valid element to add, may be the
            //element of new window
            dq.push_back(i);

            //4.See, you only need to take care, once you i becomes >= k- 1
            //you get the first window,and after that,every increment of i
            //keep creating new window,so anyway it becomes valid
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
            i++;
        }
        return ans;
    }
};
