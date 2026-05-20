class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
             // 1) remove indices out of current window [i-k+1 .. i]
            if(!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }
             // 2) maintain decreasing deque (max at front)
            //While the back element is <= current, pop back. They can never be max again.
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // 3) add current index
            //now this is the place you always add valid viable element(index)
            dq.push_back(i);

             // 4) output once first window formed
            //front of deque as it always contains max
            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
                //we do not remove front here, because we already manage
                //stale/elements out of window above;
            }
        }
        return result;
    }
};
