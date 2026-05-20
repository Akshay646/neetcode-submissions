class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i : nums){
            minHeap.push(i);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        //assuming nums will have >= k element
        return minHeap.top();
    }
};
