class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //left heap is maxHeap - max stays at top
        //right heap is miHeap - min stays on top
        if(!maxHeap.empty() && num > maxHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }

        //rebalance both the heaps
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
         if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
       double median = 0.0;
       int mx = maxHeap.size();
       int mn = minHeap.size();
        if(mx == mn){
        median = (double)(maxHeap.top() + minHeap.top()) / 2;
       }
       else{
        median = mx > mn ? maxHeap.top() : minHeap.top();
       }
       return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */