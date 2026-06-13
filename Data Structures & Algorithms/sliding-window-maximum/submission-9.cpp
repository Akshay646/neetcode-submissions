class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;
       deque<int> dq;//Stores indices of elements that are still candidates to become the maximum

       //Step 1: Process first window, and store valid elements in deque
       for(int i = 0; i < k; i++){
        //remove elements from deque if smaller than current element
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        //Add element to deque
        dq.push_back(i);
       }

       //Step 2: At this point our deque has max at front for first ever window
       //Now start exploring next windows by
        //.Removing elements which are not part of current window
        //Removing elements which are < current element as they won't be max ever
        for(int i = k; i < nums.size(); i++){
            //Add the max to result set
            ans.push_back(nums[dq.front()]);

            //Always remove elements which are not part of current window
            if(!dq.empty() && dq.front() < (i - k) + 1){
                dq.pop_front();
            }

            //remove elements which are smaller than current
            //This will help maintaining monotonic decreasing order as well as
            //max at the front(consequence)
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            //add fresh element to deque to process
            dq.push_back(i);
        }

        //Now if we process whole array and deque may still have max which we couldn't
        //add into result set, we need to add it
        if(!dq.empty()){
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
