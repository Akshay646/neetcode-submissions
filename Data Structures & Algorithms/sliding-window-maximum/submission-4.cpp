class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            //always  remove stale elements, i.e elements which are not
            //part of the current window [i - k + 1..i]
            if(!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }
            //Maintain max all the way
            //if current element at deque's front contains element 
            //< current nums[i], that element will never contribute to max in future
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            //now this is the place yuo always add valid viable element(index)
            dq.push_back(i);

            //now check if you have processed a window, if so, just get the
            //front of deque as it always contains max
            if(i >= k - 1){
                //add element as nums[dq.front()], as deque store indices
                result.push_back(nums[dq.front()]);
                //we do not remove front here, because we already manage
                //stale/elements out of window above;
            }
        }
        return result;
    }
};
