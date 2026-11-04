class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> pq;//stores indices
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            //Front always have max so far in the window
            //First makesure no stale element
            if(!pq.empty() && pq.front() < i - k + 1){
                pq.pop_front();
            }

            //now assume you encounter current nums[i] > some
            //elements in pq, those elements will not make
            //sense to be in pq since those will never be greater
            //than current or future windows, remove them
            while(!pq.empty() && nums[i] > nums[pq.back()]){
                pq.pop_back();
            }

            //since we have checked all conditions before adding
            //the element, so add now
            pq.push_back(i);

            //check if we have formed a k size window
            // Once your i exceeds k, its always a k size window
            if(i + 1 >= k){
                ans.push_back(nums[pq.front()]);
            }
        }
        return ans;
    }
};
