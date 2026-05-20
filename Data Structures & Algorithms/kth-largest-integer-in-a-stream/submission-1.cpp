class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int globalK = 0;
    KthLargest(int k, vector<int>& nums) {
        globalK = k;
        //we only maintain min heap of size k
        for(int i = 0; i < nums.size(); i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        //now you add the element in heap, if size goes beyond k, you remove top.
        //why? as we only wants to remove smallest element in case size goes beyond k
        //CASE-1: for heap = 4,5,8, assume add(2) gets called, so heap becomes 2,4,5,8
        //and we remove smaller i.e. 2, hence kth(3) largest is heaps top, i.e. 4

        //CASE-2: for heap = 4,5,8, assume add(9) gets called, so heap becomes 4,5,8,9
        //and we remove smaller i.e. 4, hence kth(3) largest is heaps top, i.e. 5
        minHeap.push(val);
        if(minHeap.size() > globalK){minHeap.pop();}
        return minHeap.top();
    }
};
