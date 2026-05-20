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
        //now we add new element in heap, if heap is already contains k elements,
        //remove smallest element(heap.top), after smallest, all elements are largest already
        //which helps make top element always the kth largest
        
        minHeap.push(val);
        if(minHeap.size() > globalK){minHeap.pop();}
        return minHeap.top();
    }
};
