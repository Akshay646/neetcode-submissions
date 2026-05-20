class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            //make sure dq does not contain elements outof range(k)
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            //now remove elements <= current i, as we have to maintain max
            //always at the front.
            //why from back, as smallers are at back, if you compre it with
            //front, you may miss smallers for sure

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            //now at this point we're sure dq.front will have max of the current
            //window\
            //i >= k - 1 is ONLY needed to prevent early output.
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
