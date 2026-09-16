class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; //{ind}
        int i = 0;
        int n = nums.size();
        vector<int> ans;
        while(i < n){
            //check if dq has stale elements/out of window elements
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }

            //check of dq has smaller elements than current element
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            //after above checks, we're sure that the element we're at is max at the
            //current window
            dq.push_back(i);

            //now check if we have generated k sized window, if so, start storing
            //max elements, max always sits at front given we're storing elements in
            //monotonically decreasing nature
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
            i++;
        }
        return ans;
    }
};
